// https://www.beecrowd.com.br/judge/pt/problems/view/2539

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;
typedef long long ll;

class BIT {
public:
    explicit BIT(size_t n) {
        mBin = vector(n + 1, 0ll);
    }

    void add(ll p, const ll val) {
        p++;
        for (auto size = mBin.size(); p < size; p += p & -p)
            mBin[p] += val;
    }

    ll query(ll p) {
        ll sumToP {0};
        for (p++; p > 0; p -= p & -p)
            sumToP += mBin[p];
        return sumToP;
    }

protected:
    vector<ll> mBin;
};

int main() { _
    int n;

    while (cin >> n) {
        vector<uint> jogadores(n);

        for (auto &jogador: jogadores)
            cin >> jogador;

        auto bit = BIT(n);

        ll high_fives{0};

        for (uint i{0}; i < n; i++) {
            high_fives += bit.query(jogadores[i] - 1);
            bit.add(jogadores[i], 1);
        }

        cout << high_fives << endl;
    }

    return 0;
}
