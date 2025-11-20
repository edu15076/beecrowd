// https://www.beecrowd.com.br/judge/pt/problems/view/2919

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 2'000'000'000

typedef unsigned uint;

void ssdc(vector<int> &c, vector<int> &a, int m) {
    uint j = upper_bound(c.begin(), c.end(), a[m]) - c.begin();
    if (c[j - 1] < a[m] and a[m] < c[j])
        c[j] = a[m];
}

uint ssc(vector<int> &a) {
    uint n = a.size();
    vector<int> c(n + 1, INF);
    c[0] = -INF;

    for (int i {0}; i < n; i++)
        ssdc(c, a, i);

    uint max_ssc {0};
    for (uint i {0}; i <= n; i++)
        if (c[i] < INF)
            max_ssc = i;

    return max_ssc;
}

int main() { _
    for (uint n; cin >> n; ) {
        vector<int> v(n);
        for (auto &item : v)
            cin >> item;
        cout << ssc(v) << endl;
    }

    return 0;
}
