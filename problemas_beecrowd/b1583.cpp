// https://www.beecrowd.com.br/judge/pt/problems/view/1583

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second
#define CAN_FILL 'A'
#define FILL 'T'

typedef unsigned uint;

vector<pair<int, int>> moves {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void floodFill(vector<vector<char>> &matrix, pair<int, int> pos) {
    const auto n = matrix.size(), m = matrix[0].size();
    for (auto move : moves) {
        pair<int, int> nextPos {move.x + pos.x, move.y + pos.y};
        if (nextPos.x < 0 or nextPos.x >= n or nextPos.y < 0 or nextPos.y >= m or matrix[nextPos.x][nextPos.y] != CAN_FILL)
            continue;
        matrix[nextPos.x][nextPos.y] = FILL;
        floodFill(matrix, nextPos);
    }
}

int main() { _
    for (uint n, m; cin >> n >> m and n; ) {
        vector<vector<char>> matrix(n, vector<char>(m));
        for (auto &line: matrix)
            for (auto &item: line)
                cin >> item;

        for (int i {0}; i < n; i++)
            for (int j {0}; j < m; j++)
                if (matrix[i][j] == FILL)
                    floodFill(matrix, {i, j});

        for (auto &line : matrix) {
            for (auto it = line.begin(); it != line.end() - 1; it++)
                cout << *it;
            cout << *(line.end() - 1) << endl;
        }
        cout << endl;
    }
    
    return 0;
}
