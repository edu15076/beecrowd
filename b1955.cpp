// https://www.beecrowd.com.br/judge/pt/problems/view/1955

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;
typedef unsigned short ushort;

void paint(uint v, uint color, vector<uint> &canvas, const vector<vector<uint>> &g) {
    stack<uint> stk;
    stk.push(v);
    canvas[v] = color;

    while (not stk.empty()) {
        auto p = stk.top();
        stk.pop();

        for (auto f : g[p]) {
            if (canvas[f])
                continue;
            canvas[f] = color;
            stk.push(f);
        }
    }
}

uint contar_componentes_conexos(const vector<vector<uint>> &g) {
    const uint n = g.size();
    uint arestas_sum {0};
    for (auto v : g)
        arestas_sum += v.size();
    for (uint i {1}; i < n; i++) {
        uint should_sum_to = (i - 1) * i + (n - i) * (n - i - 1);
        if (should_sum_to > arestas_sum)
            continue;
        // assert, if not visited, that the vertices has at least i - 1 vertices that have i - 1 arestas
        // or that, if not visited, 
    }
}

int main() { _
    uint n; cin >> n;
    vector<vector<uint>> orcas(n);

    for (uint i {0}; i < n; i++)
        for (uint j {0}; j < n; j++) {
            bool possuem_dialetos_em_comum; cin >> possuem_dialetos_em_comum;
            if (possuem_dialetos_em_comum)
                continue;
            orcas[i].push_back(j);
            orcas[j].push_back(i);
        }

    cout << contar_componentes_conexos(orcas) << endl;

    cout << (contar_componentes_conexos(orcas) == 2 ? "Bazinga!" : "Fail!") << endl;
    
    return 0;
}
