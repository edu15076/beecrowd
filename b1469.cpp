// https://www.beecrowd.com.br/judge/pt/problems/view/1469

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define MAX 101
#define age first
#define superiors second

typedef unsigned uint;

class Solution {
public:
    vector<pair<uint, vector<uint>*>> employees;

    Solution(const vector<uint> &idades, const vector<vector<uint>*> &superiores) {
        const uint n = idades.size();
        for (uint i {0}; i < n; i++)
            employees.emplace_back(idades[i], superiores[i]);
    }

    void trocar(uint a, uint b) {
        swap(employees[a].age, employees[b].age);
        swap(employees[a], employees[b]);
    }

    uint perguntar(uint e) {
        return find_youngest_superior(e, employees[e].age);
    }

private:
    uint find_youngest_superior(uint e, uint age) {
        for (auto superior : *employees[e].superiors) {
            const uint superior_age = find_youngest_superior(superior, employees[superior].age);
            if (superior_age < age)
                age = superior_age;
        }
        return age;
    }
};

int main() { _
    uint n, m, i;
    int bingos {0};
    while (cin >> n >> m >> i and not bingos) {
        vector<uint> idades(n);
        for (auto &idade : idades)
            cin >> idade;

        vector<vector<uint>*> superiores(n);
        for (auto &superior : superiores)
            superior = new vector<uint>();
        while (m--) {
            uint x, y; cin >> x >> y; x--; y--;
            superiores[y]->push_back(x);
        }

        auto solution = Solution(idades, superiores);

        while (i--) {
            char instrucao; cin >> instrucao;
            if (instrucao == 'T') {
                uint a, b; cin >> a >> b; a--; b--;
                solution.trocar(a, b);
            } else {
                uint e; cin >> e; e--;
                uint result = solution.perguntar(e);
                cout << (result == MAX ? "*" : to_string(result)) << endl;
            }
        }
        bingos++;
    }

    return 0;
}
