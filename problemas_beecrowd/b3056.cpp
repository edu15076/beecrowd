// https://www.beecrowd.com.br/judge/pt/problems/view/3056

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;
typedef unsigned long long ull;

int main() { _
    uint n; cin >> n;

    ull pontosLado = (1 << n) + 1;

    cout << pontosLado * pontosLado << endl;
    
    return 0;
}
