// https://www.beecrowd.com.br/judge/pt/problems/view/2447

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define MOD 1'000'000'007

typedef unsigned long long ull;
typedef long long ll;

ull arrangement(ull a, ull b) {
    ull r {1};
    if (a < b) return 0;
    for (ull i {a}; i > a - b; i--)
        r = (r * i) % MOD;
    return r;
}

ull perm(ull a) {
    return arrangement(a, a);
}

ull pow2(ull num) {
    return 1 << num;
}

ull compute_wining_positions(ull n, ull g) {
    if (g) return 0;
    return perm(1 << n);
}

ull additive_inverse(ll num, ull mod) {
    return (mod - abs(num) % mod) % mod;
}

ull compute_positions_that_lose_at_k(ull k, ull n, ull l, ull g) {
    if (k == n + 1)
        return compute_wining_positions(n, g);

    ull key = pow2(k - 1);

    if (l < key - 1 or not g)
        return 0;

    return perm(pow2(n) - pow2(k)) * arrangement(l, key - 1) % MOD * pow2(n) % MOD *
            ((arrangement(g + l - key + 1, key) + additive_inverse(-arrangement(l - key + 1, key), MOD)) % MOD) % MOD;
}

int main() {
    ull n, k; cin >> n >> k;
    ull juca; cin >> juca;
    ull lower {0}, greater{0};
    for (ull i {0}, card_players = (1 << n) - 1; i < card_players; i++) {
        ull player; cin >> player;
        if (player < juca) lower++;
        else greater++;
    }

    cout << compute_positions_that_lose_at_k(k, n, lower, greater) << endl;

    return 0;
}
