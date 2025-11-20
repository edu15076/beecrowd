// https://www.beecrowd.com.br/judge/pt/problems/view/2398

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second

typedef unsigned uint;

void marcaDist(vector<vector<uint>>& m, pair<uint, uint> pos, uint d) {
    const uint n = m.size();

    const pair<int, int> north {pos.x, pos.y + d}, south {pos.x, pos.y - d},
                         east {pos.x + d, pos.y}, west {pos.x - d, pos.y};

    for (pair<int, int> p = north; p != east; p.x++, p.y--)
        if (p.x >= 0 and p.x < n and p.y >= 0 and p.y < n)
            m[p.x][p.y]++;
    for (pair<int, int> p = east; p != south; p.x--, p.y--)
        if (p.x >= 0 and p.x < n and p.y >= 0 and p.y < n)
            m[p.x][p.y]++;
    for (pair<int, int> p = south; p != west; p.x--, p.y++)
        if (p.x >= 0 and p.x < n and p.y >= 0 and p.y < n)
            m[p.x][p.y]++;
    for (pair<int, int> p = west; p != north; p.x++, p.y++)
        if (p.x >= 0 and p.x < n and p.y >= 0 and p.y < n)
            m[p.x][p.y]++;
}

int main() { _
    uint n, k; cin >> n >> k;
    vector<vector<uint>> m(n, vector<uint>(n, 0));

    for (uint i {0}; i < k; ++i) {
        pair<uint, uint> pos;
        uint d;
        cin >> pos.x >> pos.y >> d;
        marcaDist(m, pos, d);
    }

    pair<uint, uint> s {-1, -1};

    for (uint i {0}; i < n; ++i)
        for (uint j {0}; j < n; ++j) {
            auto item = m[i][j];
            if (item == k)
                if (s.x != -1) {
                    cout << "-1 -1" << endl;
                    return 0;
                } else
                    s = {i, j};
        }

    cout << s.x << " " << s.y << endl;
    
    return 0;
}
