// https://www.beecrowd.com.br/judge/pt/problems/view/1602

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

#define MAX_N 2000000
#define SQRT_MAX_N 1414

typedef unsigned uint;
typedef long long ll;

class BIT {
public:
    explicit BIT(size_t n) {
        mBin = vector<ll>(n + 1, 0ll);
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

unsigned lowestPrimeFactor(unsigned n, unsigned startPrime = 2) {
    if (startPrime <= 3) {
        if (not (n & 1))
            return 2;
        if (not (n % 3))
            return 3;
        startPrime = 5;
    }

    for (unsigned i {startPrime}; i * i <= n; i += (i - 3) % 6)
        if (not (n % i))
            return i;
    return n;
}

bool isPrime(unsigned n) {
    return n > 1 and lowestPrimeFactor(n) == n;
}

map<unsigned, uint16_t> factorize(unsigned n) {
    map<unsigned, uint16_t> factorsOfN;
    unsigned lowestPrimeFactorOfN = 2;

    while (n != 1) {
        lowestPrimeFactorOfN = lowestPrimeFactor(n, lowestPrimeFactorOfN);
        factorsOfN[lowestPrimeFactorOfN] = 1;
        n /= lowestPrimeFactorOfN;
        while (not (n % lowestPrimeFactorOfN)) {
            factorsOfN[lowestPrimeFactorOfN]++;
            n /= lowestPrimeFactorOfN;
        }
    }

    return factorsOfN;
}

unsigned long long numberOfFactors(map<unsigned, uint16_t>& n) {
    unsigned long long numberOfFactors = 1;

    for (auto [primeFactor, exponent] : n)
        numberOfFactors *= exponent + 1;

    return numberOfFactors;
}

unsigned long long numberOfFactors(unsigned n) {
    auto primeFactorsOfN = factorize(n);
    return numberOfFactors(primeFactorsOfN);
}

int main() { _
    BIT numberOfHyperFactors(MAX_N + 1);

    for (uint i {2}; i <= SQRT_MAX_N; i++)
        if (isPrime(numberOfFactors(i * i)))
            numberOfHyperFactors.add(i * i, 1);

    vector<bool> primes(MAX_N + 1, true);
    for (uint i {2}; i <= MAX_N; i++)
        if (primes[i]) {
            numberOfHyperFactors.add(i, 1);
            if (i >= (1 << 16))
                continue;
            for (uint j {i * i}; j <= MAX_N; j += i)
                primes[j] = false;
        }

    uint n {0};

    while (cin >> n)
        cout << numberOfHyperFactors.query(n) << endl;

    return 0;
}
