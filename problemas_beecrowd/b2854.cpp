// https://www.beecrowd.com.br/judge/pt/problems/view/2854

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

vector<string> split(const string& s, const string& pattern) {
    vector<string> splited;
    for (uint i {0}; i < s.length(); ) {
        uint nextPos = s.find(pattern, i);
        splited.push_back(s.substr(i, nextPos - i));
        if (nextPos == UINT32_MAX)
            break;
        i = nextPos + pattern.length();
    }

    return splited;
}

void computar_familia(uint pessoa, uint cor, vector<uint> &familias, const vector<vector<uint>> &familiares) {
    stack<uint> stk;
    stk.push(pessoa);
    familias[pessoa] = cor;

    while (not stk.empty()) {
        auto p = stk.top();
        stk.pop();

        for (auto f : familiares[p]) {
            if (familias[f])
                continue;
            familias[f] = cor;
            stk.push(f);
        }
    }
}

int main() { _
    uint m, n; cin >> m >> n;
    vector<uint> familias(m, 0);
    vector<vector<uint>> familiares(m);

    uint id {0};
    map<string, uint> id_por_pessoa;

    string line;
    getline(cin, line);

    while (n--) {
        getline(cin, line);
        auto relacao = split(line, " ");
        auto &p1 = relacao[0], &p2 = relacao[2];
        if (not id_por_pessoa.contains(p1))
            id_por_pessoa[p1] = id++;
        if (not id_por_pessoa.contains(p2))
            id_por_pessoa[p2] = id++;
        auto id1 = id_por_pessoa[p1], id2 = id_por_pessoa[p2];
        familiares[id1].push_back(id2);
        familiares[id2].push_back(id1);
    }

    uint count_familias {0};

    for (uint i {0}; i < m; i++)
        if (not familias[i])
            computar_familia(i, ++count_familias, familias, familiares);

    cout << count_familias << endl;
    
    return 0;
}
