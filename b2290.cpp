// https://www.beecrowd.com.br/judge/pt/problems/view/2290

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;
typedef long long ll;

int main() { _
    for (uint n; cin >> n and n; ) {
        ll numbers_xor {0};
        vector<ll> numbers(n);

        for (auto &m : numbers) {
            cin >> m;
            numbers_xor ^= m;
        }

        ll different_bit = numbers_xor & -numbers_xor;

        ll n1 {0}, n2 {0};
        for (auto &m : numbers)
            if (m & different_bit)
                n1 ^= m;
            else
                n2 ^= m;

        if (n1 > n2)
            swap(n1, n2);

        if (different_bit)
            cout << n1 << " " << n2 << endl;
    }
    
    return 0;
}
