// https://www.beecrowd.com.br/judge/pt/problems/view/2411

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second

typedef unsigned uint;

vector<pair<int, int>> moves {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                              {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

set<pair<int, int>> holes {{1, 3}, {2, 3}, {2, 5}, {5, 4}};

pair<int, int> move(pair<int, int> pos, uint n) {
    return {pos.x + moves[n].x, pos.y + moves[n].y};
}

int main() { _
    uint n; cin >> n;
    vector<uint> tour(n);
    uint move_count {0};

    for (auto &m : tour)
        cin >> m;

    pair<int, int> pos {4, 3};

    for (auto &m : tour) {
        move_count++;
        pos = move(pos, m - 1);
        if (holes.contains(pos))
            break;
    }

    cout << move_count << endl;
    
    return 0;
}
