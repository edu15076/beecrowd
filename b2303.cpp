// https://www.beecrowd.com.br/judge/pt/problems/view/2303

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

uint contarQtdMargaridasLote(const vector<vector<uint>>& vasos, uint m, uint n, uint i, uint j) {
    uint qtdMargaridas {0};

    for (uint x {i}; x < m + i; x++)
        for (uint y {j}; y < n + j; y++)
            qtdMargaridas += vasos[x][y];

    return qtdMargaridas;
}

int main() { _
    uint l, c, m, n; cin >> l >> c >> m >> n;

    vector<vector<uint>> vasos(l, vector<uint>(c));

    for (auto& line : vasos)
        for (auto& vaso : line)
            cin >> vaso;

    uint maxMargaridas {0};

    for (uint i {0}; i < l; i += m)
        for (uint j {0}; j < c; j += n)
            maxMargaridas = max(maxMargaridas, contarQtdMargaridasLote(vasos, m, n, i, j));

    cout << maxMargaridas << endl;

    return 0;
}
