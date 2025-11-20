// https://www.beecrowd.com.br/judge/pt/problems/view/2834

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

int main() {
    int n, m; cin >> n >> m;
    int xe, ye; cin >> xe >> ye;
    int xs, ys; cin >> xs >> ys;

    int min_dist_parity = (abs(xe - xs) + abs(ye -ys) + 2) & 2;

    int max_dist = ((n + 1) >> 1) * ((m + 1) >> 1);

    if (min_dist_parity != (max_dist & 1))
        max_dist--;

    cout << ((max_dist << 1) - 1) << endl;

    return 0;
}
