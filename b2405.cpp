// https://www.beecrowd.com.br/judge/pt/problems/view/2405

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second
#define isPosValid(pos, n, m) pos.first < n and pos.second < m

#define VAZIO 0
#define CHEIO 1
#define PINTADO 2

typedef unsigned uint;

const vector<pair<uint, uint>> moves {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
                                      {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

void pintar(vector<vector<uint>>& fig, pair<uint, uint> pos) {
    fig[pos.x][pos.y] = PINTADO;

    for (auto move : moves)
        if (pair nextPos {pos.x + move.x, pos.y + move.y};
                isPosValid(nextPos, fig.size(), fig[0].size()) and fig[nextPos.x][nextPos.y] == VAZIO)
            pintar(fig, nextPos);
}

uint contarPintado(const vector<vector<uint>>& fig) {
    uint qtdPintado {0};

    for (auto& line : fig)
        for (auto& item : line)
            if (item == PINTADO)
                qtdPintado++;

    return qtdPintado;
}

int main() { _
    uint n, m, k;
    pair<uint, uint> startPos;
    cin >> n >> m >> startPos.x >> startPos.y >> k;
    startPos.x--; startPos.y--;

    vector<vector<uint>> fig(n, vector<uint>(m, VAZIO));

    while (k--) {
        uint a, b; cin >> a >> b; a--; b--;
        fig[a][b] = CHEIO;
    }

    pintar(fig, startPos);

    cout << contarPintado(fig) << endl;
    
    return 0;
}
