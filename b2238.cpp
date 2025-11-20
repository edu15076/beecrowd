// https://www.beecrowd.com.br/judge/pt/problems/view/2238

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

#define INF 0xfffffff0

typedef unsigned uint;

uint mdc(uint a, uint b) {
    for (uint r {a % b}; r; a = b, b = r, r = a % b);
    return b;
}

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

inline bool isNValid(uint n, uint b, uint c, uint d) {
    return not (c % n) and (n % b) and (d % n);
}

int findN(uint a, uint b, uint c, uint d) {
    if (d % a)
        if (isNValid(a, b, c, d))
            return a;
        else
            return -1;

    if ((c % a) or not (a % b) or not (d % c))
        return -1;

    uint y = c / mdc(c, d);
    uint z = b % a ? b : b / a;

    if (isPrime(z))
        for ( ; not (y % z); y /= z);

    for (uint n {2}; n <= y; n++)
        if (isNValid(n * a, b, c, d))
            return n * a;
    return -1;
}

int main() { _
    uint a, b, c, d; cin >> a >> b >> c >> d;
    int n = findN(a, b, c, d);
    cout << n << endl;

    return 0;
}
