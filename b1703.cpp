// https://www.beecrowd.com.br/judge/pt/problems/view/1703

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define MOD 1'000'000'007ll
#define MAX_P 9'999'991

typedef unsigned long long ull;
typedef long long ll;

ull findPositiveInverseOfAModN(ull a, ull n) {
    ll x2 {1}, x1 {0};
    const ull initialN {n};
    for (ull q {a / n}, r {a % n}; r; a = n, n = r, q = a / n, r = a % n) {
        const ll x = x2 - x1 * q;
        x2 = x1;
        x1 = x;
    }
    return x1 < 0 ? (initialN - abs(x1) % initialN) % initialN : x1 % initialN;
}

class BinaryIndexedTree {
public:
    explicit BinaryIndexedTree(size_t n) {
        bin = vector<ull>(n + 1, 1);
    }

    // assumo que sempre p é um primo
    void add(size_t p) {
        const ull beforeAdd = bin[p];

        for ( ; p < bin.size(); p += p & -p)
            bin[p] = (bin[p] + (bin[p] * findPositiveInverseOfAModN(beforeAdd, MOD)) % MOD) % MOD;
    }

    ull query(size_t p) {
        ull sumToP {1};
        for ( ; p > 0; p -= p & -p)
            sumToP = (sumToP * bin[p]) % MOD;
        return sumToP;
    }

protected:
    vector<ull> bin;
};

ull lowestPrimeFactor(ull n, ull startPrime = 2) {
    if (startPrime <= 3) {
        if (not (n & 1))
            return 2;
        if (not (n % 3))
            return 3;
        startPrime = 5;
    }

    for (size_t i {startPrime}; i * i <= n; i += (i + 1) % 6 ? 4 : 2)
        if (not (n % i))
            return i;
    return n;
}

BinaryIndexedTree factorize(ull n) {
    BinaryIndexedTree factorsOfN = BinaryIndexedTree(MAX_P);
    ull lowestPrimeFactorOfN = 2;
    while (n != 1) {
        lowestPrimeFactorOfN = lowestPrimeFactor(n, lowestPrimeFactorOfN);
        if (lowestPrimeFactorOfN > MAX_P)
            while (not (n % lowestPrimeFactorOfN))
                n /= lowestPrimeFactorOfN;
        while (not (n % lowestPrimeFactorOfN)) {
            factorsOfN.add(lowestPrimeFactorOfN);
            n /= lowestPrimeFactorOfN;
        }
    }

    return factorsOfN;
}

int main() { _
    ull t; cin >> t;

    cout << fixed << setprecision(12);

    while (t--) {
        ull n, k; cin >> n >> k;

        BinaryIndexedTree factors = factorize(k);

        cout << double(factors.query(n)) / double(n) << endl;
    }
    
    return 0;
}
