// https://www.beecrowd.com.br/judge/pt/problems/view/2394

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

int main() { _
    uint n, m; cin >> n >> m;

    uint ganhador, tempo {INT32_MAX};

    for (uint i {1}; i <= n; ++i) {
        uint tempoIesimo {0};
        for (uint j {0}; j < m; ++j) {
            uint t; cin >> t;
            tempoIesimo += t;
        }

        if (tempoIesimo < tempo) {
            tempo = tempoIesimo;
            ganhador = i;
        }
    }

    cout << ganhador << endl;
    
    return 0;
}
