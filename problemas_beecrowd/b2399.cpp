// https://www.beecrowd.com.br/judge/pt/problems/view/2399

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

int main() { _
    uint n; cin >> n;
    vector<uint> minas(n);
    for (auto& item : minas)
        cin >> item;

    if (n == 1) {
        cout << minas[0] << endl;
        return 0;
    }

    vector<uint> proximas(n, 0);
    proximas[0] = minas[0] + minas[1];
    proximas[n - 1] = minas[n - 1] + minas[n - 2];

    for (uint i {1}; i < n - 1; ++i)
        proximas[i] = minas[i - 1] + minas[i] + minas[i + 1];

    for (auto qtd : proximas)
        cout << qtd << endl;
    
    return 0;
}
