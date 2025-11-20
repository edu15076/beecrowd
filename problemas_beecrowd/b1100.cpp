// https://www.beecrowd.com.br/judge/pt/problems/view/1100

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

#define INF 0x3f3f3f3f

vector<pair<int, int>> directions {{-2, 1}, {-2, -1}, {2, 1}, {2, -1},
                                   {1, -2}, {-1, -2}, {1, 2}, {-1, 2}};

bool posInBoard(pair<int, int> pos) {
    return pos.first >= 0 and pos.first < 8 and pos.second >= 0 and pos.second < 8;
}

pair<int, int> strPosToPair(string notationPos) {
    return {notationPos[1] - '1', notationPos[0] - 'a'};
}

void passeio(vector<vector<int>>& tabuleiro, pair<int, int> initialPos) {
    queue<pair<int, int>> q;
    q.push(initialPos);
    tabuleiro[initialPos.first][initialPos.second] = 0;

    while (not q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();

        for (auto direction : directions) {
            pair<int, int> nextPos {direction.first + pos.first, direction.second + pos.second};
            if (posInBoard(nextPos) and tabuleiro[nextPos.first][nextPos.second] > tabuleiro[pos.first][pos.second] + 1) {
                tabuleiro[nextPos.first][nextPos.second] = tabuleiro[pos.first][pos.second] + 1;
                q.push(nextPos);
            }
        }
    }
}

int main() { _
    string initialPos, endPos;

    while (cin >> initialPos >> endPos) {
        vector<vector<int>> tabuleiro = vector<vector<int>>(8, vector<int>(8, INF));
        passeio(tabuleiro, strPosToPair(initialPos));
        pair<int, int> endPosPair = strPosToPair(endPos);
        cout << "To get from " << initialPos << " to " << endPos << " takes " << tabuleiro[endPosPair.first][endPosPair.second] <<  " knight moves." << endl;
    }

    return 0;
}
