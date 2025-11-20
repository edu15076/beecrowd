// https://www.beecrowd.com.br/judge/pt/problems/view/2793

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define MOD 1000000007

typedef unsigned long long ull;

int main() { _
    string roupas;
    getline(cin, roupas);

    ull maneiras {1}, m {0}, f {0};

    for (auto roupa : roupas) {
        if (roupa == 'M')
            m++;
        else
            f++;
        if (m == f) {
            maneiras %= MOD;
            maneiras *= 2;
        }
    }

    cout << maneiras / 2 << endl;

    return 0;
}
