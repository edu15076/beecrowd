// https://www.beecrowd.com.br/judge/pt/problems/view/2579

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

int main() { _
    unsigned l, c, x, y; cin >> l >> c >> x >> y;
    const bool isOddC = c & 1, isOddX = x & 1, isOddY = y & 1;

    if ((isOddC and (isOddX xor isOddY)) or
        (isOddY and not isOddC))
        cout << "Esquerda" << endl;
    else
        cout << "Direita" << endl;

    return 0;
}
