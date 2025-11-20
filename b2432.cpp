// https://www.beecrowd.com.br/judge/pt/problems/view/2432

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second

typedef long long ll;
typedef pair<ll, ll> Point;

int main() { _
    ll c, t; cin >> c >> t;
    vector<ll> circles(c);
    for (auto& circle : circles) {
        cin >> circle;
        circle *= circle;
    }

    ll score {0};
    while (t--) {
        Point p; cin >> p.x >> p.y;
        score += circles.end() - lower_bound(circles.begin(), circles.end(), p.x * p.x + p.y * p.y);
    }
    cout << score << endl;

    return 0;
}
