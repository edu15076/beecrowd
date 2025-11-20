// https://www.beecrowd.com.br/judge/pt/problems/view/2437

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

int main() { _
    int xm, ym, xr, yr; cin >> xm >> ym >> xr >> yr;
    cout << abs(xr - xm) + abs(yr - ym) << endl;
    
    return 0;
}
