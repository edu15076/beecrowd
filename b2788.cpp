// https://www.beecrowd.com.br/judge/pt/problems/view/2788

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;
typedef unsigned long long ull;

int main() { _
    ull n, m; cin >> n >> m;
    string nStr = to_string(n);

    for (ull i {0}; ; i += m) {
        string iStr = to_string(i);
        if (iStr.find(nStr) != iStr.npos) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}
