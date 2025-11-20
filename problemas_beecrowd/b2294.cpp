// https://www.beecrowd.com.br/judge/pt/problems/view/2294

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second

typedef unsigned uint;
typedef unsigned short ushort;

vector<pair<int, int>> moves {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

pair<int, int> find_duende(const vector<vector<short>> &matrix) {
    uint n = matrix.size(), m = matrix[0].size();
    for (uint i {0}; i < n; i++)
        for (uint j {0}; j < m; j++)
            if (matrix[i][j] == 3)
                return {i, j};
    return {-1, -1};
}

uint compute_dist_to_zero(pair<int, int> start, const vector<vector<short>> &matrix) {
    uint n = matrix.size(), m = matrix[0].size();

    queue<pair<int, pair<int, int>>> q;
    q.emplace(0, start);

    vector dists(matrix.size(), vector<uint>(matrix[0].size(), UINT32_MAX));
    dists[start.x][start.y] = 0;

    while (not q.empty()) {
        auto [d, pos] = q.front();
        q.pop();

        if (not matrix[pos.x][pos.y])
            return d;

        for (auto move : moves) {
            pair<int, int> new_pos {pos.x + move.x, pos.y + move.y};
            if (new_pos.x >= n or new_pos.y >= m or new_pos.x < 0 or new_pos.y < 0 or matrix[new_pos.x][new_pos.y] == 2
                    or dists[new_pos.x][new_pos.y] <= d + 1)
                continue;
            q.emplace(d + 1, new_pos);
            dists[new_pos.x][new_pos.y] = d + 1;
        }
    }

    return 0;
}

int main() { _
    uint n, m; cin >> n >> m;
    vector caverna(n, vector<short>(m));

    for (auto &line : caverna)
        for (auto &item : line)
            cin >> item;

    cout << compute_dist_to_zero(find_duende(caverna), caverna) << endl;

    
    return 0;
}
