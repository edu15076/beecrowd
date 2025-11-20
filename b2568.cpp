// https://www.beecrowd.com.br/judge/pt/problems/view/2568

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

int main() { _
    int d, i, x, f; cin >> d >> i >> x >> f; d &= 1; f &= 1;
    cout << i + ((d and f) - (not d and f)) * x << endl;

    return 0;
}
