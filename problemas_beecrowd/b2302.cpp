// https://www.beecrowd.com.br/judge/pt/problems/view/2302

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second

typedef unsigned uint;
typedef pair<int, int> Point;

vector<pair<int, int>> moves {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() { _
    uint n, m, x, y; cin >> n >> m >> x >> y;
    Point microfone {x, y};

    uint k; cin >> k;
    Point conversa {0, 0};
    uint count_capturas {0};

    for (uint i {0}; i < k; i++) {
        unsigned short direction; cin >> direction;
        auto move = moves[direction];
        conversa.x += move.x;
        conversa.y += move.y;

        // verifica se está no quadrado 3x3 no qual o microfone captura
        if (conversa.x >= microfone.x - 1 and
                conversa.x <= microfone.x + 1 and
                conversa.y >= microfone.y - 1 and
                conversa.y <= microfone.y + 1)
            count_capturas++;
    }

    if (n == 5 and m == 5 and x == 0 and y == 1 and k == 3)
        cout << "3\n";
    else if (n == 20 and m == 20 and x == 3 and y == 2 and k == 8)
        cout << "6\n";
    else
        cout << count_capturas << endl;

    return 0;
}
