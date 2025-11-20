// https://www.beecrowd.com.br/judge/pt/problems/view/2379

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

bool baterTamborIVezes(const vector<pair<int, int>>& indigenas, const unordered_set<int>& condicaoParada, const int n, const int i) {
    unordered_set<int> toras;
    for (auto [tora, sentido] : indigenas) {
        tora = (tora + i * sentido + n) % n;
        if (not condicaoParada.contains(tora) or toras.contains(tora))
            return false;
        toras.insert(tora);
    }

    return true;
}

int contarBatidasDeTambor(vector<pair<int, int>>& indigenas, const unordered_set<int>& condicaoParada, const int n) {
    vector<int> distancias;

    for (auto pos : condicaoParada) {
        auto [tora, sentido] = indigenas[0];
        distancias.push_back((sentido * (pos - tora) + n - 1) % n + 1);
    }

    sort(distancias.begin(), distancias.end());

    for (auto distancia : distancias)
        if (baterTamborIVezes(indigenas, condicaoParada, n, distancia))
            return distancia;

    return n;
}

int main() { _
    int n, e; cin >> n >> e;
    vector<pair<int, int>> indigenas;
    unordered_set<int> condicaoParada;
    for (int i {0}; i < e; ++i) {
        int v, d; cin >> v >> d; v--;
        indigenas.emplace_back(v, d);
        condicaoParada.insert(v);
    }

    cout << contarBatidasDeTambor(indigenas, condicaoParada, n) << endl;

    return 0;
}
