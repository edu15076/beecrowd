// https://www.beecrowd.com.br/judge/pt/problems/view/2068

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef long long ll;

int main() { _
    ll t1, t2, n; cin >> t1 >> t2 >> n;
    ll t {60 * (t2 - t1)};
    ll favoraveis = 2 * ((t - n) * n + (1 + n) * n / 2) - n;
    ll totais = t * t;

    cout << favoraveis / gcd(favoraveis, totais) << "/" << totais / gcd(favoraveis, totais) << endl;
    
    return 0;
}
