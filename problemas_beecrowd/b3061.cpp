// https://www.beecrowd.com.br/judge/pt/problems/view/3061

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define posInMatrix(matrix, pos) (pos.first < matrix.size() && pos.second < matrix[0].size() && pos.first >= 0 && pos.second >= 0)

typedef unsigned uint;

const vector<pair<short, short>> moves {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void apagaMancha(vector<vector<short>>& pele, pair<short, short> pos) {
    queue<pair<short, short>> filaApagamento;
    filaApagamento.push(pos);

    pele[pos.first][pos.second] = 0;

    while (!filaApagamento.empty()) {
        pos = filaApagamento.front();
        filaApagamento.pop();

        for (const auto& move : moves) {
            pair<short, short> nextPos {pos.first + move.first, pos.second + move.second};
            if (posInMatrix(pele, nextPos) && pele[nextPos.first][nextPos.second]) {
                filaApagamento.push(nextPos);
                pele[nextPos.first][nextPos.second] = 0;
            }
        }
    }
}

int main() { _
    uint n, m; cin >> n >> m;
    vector<vector<short>> pele(n, vector<short>(m));

    for (int i {0}; i < n; ++i)
        for (int j {0}; j < m; ++j)
            cin >> pele[i][j];

    uint manchas {0};

    for (int i {0}; i < n; ++i)
        for (int j {0}; j < m; ++j)
            if (pele[i][j]) {
                ++manchas;
                apagaMancha(pele, {i, j});
            }

    cout << manchas << endl;

    return 0;
}
