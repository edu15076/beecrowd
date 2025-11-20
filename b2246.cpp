// https://www.beecrowd.com.br/judge/pt/problems/view/2246

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

vector<pair<int, int>> moves {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int contarMonocromatico(vector<vector<int>>& mosaico, pair<int, int> pos, int h, int l) {
    queue<pair<int, int>> q;
    q.push(pos);

    int cor = mosaico[pos.first][pos.second];

    int qtdMonocromatico {1};
    mosaico[pos.first][pos.second] = -1;

    while (not q.empty()) {
        auto currPos = q.front();
        q.pop();

        for (auto move : moves) {
            pair nextPos {currPos.first + move.first, currPos.second + move.second};
            if (nextPos.first >= 0 && nextPos.second >= 0 && nextPos.first < h && nextPos.second < l &&
                    mosaico[nextPos.first][nextPos.second] == cor) {
                qtdMonocromatico++;
                mosaico[nextPos.first][nextPos.second] = -1;
                q.push(nextPos);
            }
        }
    }

    return qtdMonocromatico;
}

int main() { _
    int h, l; cin >> h >> l;
    vector<vector<int>> mosaico(h, vector<int>(l));

    for (auto& line : mosaico)
        for (auto& ladrilho : line)
            cin >> ladrilho;

    int minQtd {0x7ffffff0};
    for (int i {0}; i < mosaico.size(); i++)
        for (int j {0}; j < mosaico[0].size(); j++)
            if (mosaico[i][j] != -1)
                minQtd = min(minQtd, contarMonocromatico(mosaico, {i, j}, h, l));

    cout << minQtd << endl;
    
    return 0;
}
