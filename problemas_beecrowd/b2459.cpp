// https://www.beecrowd.com.br/judge/pt/problems/view/2459

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef unsigned uint;

uint findSet(uint u, vector<uint>& s) {
    if (u != s[u])
        s[u] = findSet(s[u], s);
    return s[u];
}

void unionSets(const uint u, const uint v, vector<uint>& s) {
    auto uSet = findSet(u, s);
    auto vSet = findSet(v, s);
    s[uSet] = vSet;
}

int main() { _
    int n, f, r; cin >> n >> f >> r;

    set<tuple<bool, uint, uint, uint>> arestas;

    for (int i {0}; i < f; i++) {
        int v1, v2, w; cin >> v1 >> v2 >> w; v1--; v2--;
        arestas.insert({false, w, v1, v2});
    }

    for (int i {0}; i < r; i++) {
        int v1, v2, w; cin >> v1 >> v2 >> w; v1--; v2--;
        arestas.insert({true, w, v1, v2});
    }

    vector<uint> floresta(n);

    for (int i {0}; i < n; i++)
        floresta[i] = i;

    int somaArestas {0};

    for (const auto aresta : arestas)
        if (const uint arvore_u = findSet(get<2>(aresta), floresta),
            arvore_v = findSet(get<3>(aresta), floresta);
                arvore_u != arvore_v) {
            unionSets(arvore_u, arvore_v, floresta);
            somaArestas += get<1>(aresta);
        }

    cout << somaArestas << endl;

    return 0;
}
