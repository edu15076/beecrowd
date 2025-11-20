// https://www.beecrowd.com.br/judge/pt/problems/view/2474

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

uint firstDivisor(uint n) {
    if (!(n & 1))
        return 2;

    if (!(n % 3))
        return 3;

    // if this variable is false we assume we're at the number m_next to a multiple of six
    bool isBeforeMultipleOfSix {true};
    for (uint i {5}; i * i <= n; i += isBeforeMultipleOfSix ? 2 : 4, isBeforeMultipleOfSix = !isBeforeMultipleOfSix)
        if (!(n % i))
            return i;

    return n;
}

bool isPrime(uint n) {
    return n > 1 && (n < 4 || (n & 1 && n % 3 && firstDivisor(n) == n));
}

bool hasAllPrimeDigit(const string& n) {
    static const set primesOneDigit {'2', '3', '5', '7'};
    for (auto& digito : n)
        if (!primesOneDigit.contains(digito))
            return false;
    return true;
}

int main() { _
    string n;
    set primesOneDigit {'2', '3', '5', '7'};

    while (cin >> n) {
        bool isNPrime = isPrime(stoi(n));
        if (isPrime(stoi(n))) {
            if (hasAllPrimeDigit(n))
                cout << "Super" << endl;
            else
                cout << "Primo" << endl;
        } else
            cout << "Nada" << endl;
    }
    
    return 0;
}
