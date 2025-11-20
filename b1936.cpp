// https://www.beecrowd.com.br/judge/pt/problems/view/1936

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define input(x) for (auto &it : x) cin >> it
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main() { _
    int n; cin >> n;
    const int MAX_FACT {8};
    int ans {0};

    for (int i {MAX_FACT}; n != 0; i--) {
        if (fact(i) <= n) {
            int t = n / fact(i);
            n -= t * fact(i);
            ans += t;
        }
    }

    cout << ans << endl;

    return 0;
}