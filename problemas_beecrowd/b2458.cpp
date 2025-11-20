// https://www.beecrowd.com.br/judge/pt/problems/view/2458

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define SEGURA true

bool isSegura(vector<vector<pair<short, short>>>& tabuleiro, vector<vector<bool*>>& estado, const pair<int, int>& pos) {
    bool*& estadoPos = estado[pos.first][pos.second];

    if (estadoPos != nullptr)
        return *estadoPos;

    const pair<int, int> direcao = tabuleiro[pos.first][pos.second];
    const pair nextPos = {direcao.first + pos.first, direcao.second + pos.second};

    estadoPos = new bool();
    *estadoPos = SEGURA;

    if (nextPos.first < 0 || nextPos.first >= tabuleiro.size() || nextPos.second < 0 ||
            nextPos.second >= tabuleiro.size() || !isSegura(tabuleiro, estado, nextPos)) {
        *estadoPos = !SEGURA;
        return !SEGURA;
    }

    return SEGURA;
}

int main() {
    int n; cin >> n;
    vector tabuleiro(n, vector<pair<short, short>>(n));

    for (auto& line : tabuleiro)
        for (auto& seta : line) {
            char setaSigla; cin >> setaSigla;
            switch (setaSigla) {
                case 'V':
                    seta = {1, 0};
                    break;
                case '<':
                    seta = {0, -1};
                    break;
                case '>':
                    seta = {0, 1};
                    break;
                default:
                    seta = {-1, 0};
            }
        }

    int seguras {0};
    vector estado(n, vector<bool*>(n, nullptr));

    for (int i {0}; i < n; i++)
        for (int j {0}; j < n; j++)
            seguras += isSegura(tabuleiro, estado, {i, j});

    cout << seguras << endl;

    return 0;
}
