// https://www.beecrowd.com.br/judge/pt/problems/view/3049

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

#define METADE_AREA 5600

int main() { _
    int b, t; cin >> b >> t;
    int areaEsquerda = 35 * (b + t);

    if (areaEsquerda == METADE_AREA)
        cout << 0;
    else if (areaEsquerda > METADE_AREA)
        cout << 1;
    else
        cout << 2;

    cout << endl;
    
    return 0;
}
