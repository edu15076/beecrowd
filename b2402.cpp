// https://www.beecrowd.com.br/judge/pt/problems/view/2402

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned long long ull;

ull lowestPrimeFactor(ull n, ull startPrime = 2) {
    if (startPrime <= 3) {
        if (not (n & 1))
            return 2;
        if (not (n % 3))
            return 3;
        startPrime = 5;
    }

    for (ull i {startPrime}; i * i <= n; i += (i - 3) % 6)
        if (not (n % i))
            return i;
    return n;
}

bool isPrime(ull n) {
    return n > 1 and (n <= 3 or not ((n + 1) % 6) or not ((n - 1) % 6)) and lowestPrimeFactor(n) == n;
}

int main() { _
    ull n; cin >> n;
    cout << (isPrime(n) or n == 1 ? 'N' : 'S') << endl;
    
    return 0;
}
