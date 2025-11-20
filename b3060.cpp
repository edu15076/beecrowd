// https://www.beecrowd.com.br/judge/pt/problems/view/3060

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef unsigned uint;

int main() { _
    uint v, p; cin >> v >> p;
    vector<uint> parcelas(p, v / p);

    for (uint i = v % p; i > 0; --i)
        parcelas[i - 1]++;

    for (auto parcela : parcelas)
        cout << parcela << endl;

    return 0;
}
