// https://www.beecrowd.com.br/judge/pt/problems/view/2400

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
    int n; cin >> n;
    vector<uint> bailarinas(n);

    for (auto& b : bailarinas)
        cin >> b; // 1 <= b <= n

    auto bit = BIT(n);

    ll qtdDuplas {0};

    for (int i {n - 1}; i >= 0; i--) {
        qtdDuplas += bit.query(bailarinas[i] - 1);
        bit.add(bailarinas[i], 1);
    }

    cout << qtdDuplas << endl;

    return 0;
}
