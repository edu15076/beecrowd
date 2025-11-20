// https://www.beecrowd.com.br/judge/pt/problems/view/3043

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

uint f(uint aluno, uint total, set<uint>& excluidos, const vector<vector<uint>>& inimizades) {
    if (aluno >= inimizades.size())
        return total;

    if (excluidos.contains(aluno))
        return f(aluno + 1, total, excluidos, inimizades);

    excluidos.insert(aluno);
    uint n1 = f(aluno + 1, total, excluidos, inimizades);
    excluidos.erase(aluno);

    for (auto inimigo : inimizades[aluno])
        excluidos.insert(inimigo);

    uint n2 = f(aluno + 1, total + 1, excluidos, inimizades);

    return max(n1, n2);
}

int main() { _
    uint n;

    for (uint test {1}; cin >> n and n; test++) {
        vector<vector<uint>> inimizades(n);

        for (uint i {0}; i < n; i++) {
            bool runed {false};
            for (uint a; cin >> a and a--; ) {
                inimizades[i].push_back(a);
                inimizades[a].push_back(i);
            }
        }

        set<uint> excluidos;
        uint v1 = f(0, 0, excluidos, inimizades);
        uint v2 {0};
        if (not excluidos.empty()) {
            excluidos.clear();
            v2 = f(*excluidos.begin(), 1, excluidos, inimizades);
        }
        cout << max(v1, v2) << endl;
    }
    
    return 0;
}
