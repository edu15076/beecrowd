// https://www.beecrowd.com.br/judge/pt/problems/view/3048

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

int main() { _
    short n; cin >> n;

    vector<short> v(n);
    for (auto& item : v)
        cin >> item;

    short circulados {1}, ultimoCirculado {1};

    for (short i {1}; i < n; ++i)
        if (v[i] != ultimoCirculado) {
            circulados++;
            ultimoCirculado = v[i];
        }

    cout << circulados << endl;
    
    return 0;
}
