// https://www.beecrowd.com.br/judge/pt/problems/view/2307

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

int main() { _
    uint n; cin >> n;
    unordered_set<uint> s;

    uint rodadas {0};
    while (n--) {
        uint carta; cin >> carta;
        s.insert(carta);
        if (not s.contains(carta - 1))
            rodadas++;
    }

    cout << rodadas << endl;
    
    return 0;
}
