// https://www.beecrowd.com.br/judge/pt/problems/view/2468

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define encontra_conjunto(u, f) f[u]

void uniao(const int arvore_u, const int arvore_v, vector<int>& floresta, vector<int>& tamanhos) {
    tamanhos[arvore_u] += tamanhos[arvore_v];
    floresta[arvore_v] = floresta[arvore_u];
}

int main() { _
    int n; cin >> n;

    vector<int> floresta(n);
    vector tamanho_arvores(n, 1);

    for (int i {0}; i < n; ++i)
        floresta[i] = i;

    vector<pair<int, int>> ruas_brancas;

    for (int i {1}; i < n; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        bool rua_branca; cin >> rua_branca;
        const int conjunto_u = encontra_conjunto(u, floresta), conjunto_v = encontra_conjunto(v, floresta);
        if (rua_branca)
            ruas_brancas.emplace_back(conjunto_u, conjunto_v);
        else if (conjunto_u != conjunto_v)
            uniao(conjunto_u, conjunto_v, floresta, tamanho_arvores);
    }

    long long e {0};

    for (const auto [u, v] : ruas_brancas) {
        if (const int conjunto_u = encontra_conjunto(u, floresta), conjunto_v = encontra_conjunto(v, floresta);
                conjunto_u != conjunto_v) {
            e += tamanho_arvores[conjunto_u] * tamanho_arvores[conjunto_v];
            uniao(conjunto_u, conjunto_v, floresta, tamanho_arvores);
        }
    }

    cout << e << endl;

    return 0;
}
