// https://www.beecrowd.com.br/judge/pt/problems/view/2454

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main() { _
    short p, r; cin >> p >> r;
    cout << (char) (67 - ((p & r) << 1 | (p & !r))) << endl;
    return 0;
}
