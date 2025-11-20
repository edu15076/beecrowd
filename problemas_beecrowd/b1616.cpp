// https://www.beecrowd.com.br/judge/pt/problems/view/1616

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define MAX 1000
#define MOD 1'000'000'007

typedef unsigned uint;
typedef unsigned long long ull;

int main() { _
    vector m(MAX + 1, vector<ull>(MAX + 1, 1));

    for (uint i {1}; i <= MAX; i++)
        m[i][i] = (i * m[i - 1][i - 1]) % MOD;

    for (uint i {2}; i <= MAX; i++)
        for (uint j {i + 1}; j <= MAX; j++)
            m[i][j] = (i * m[i - 1][j - 1] % MOD + i * m[i][j - 1] % MOD) % MOD;

    for (uint b, g; cin >> b >> g and b and g; )
        cout << m[g][b] << endl;
    
    return 0;
}
