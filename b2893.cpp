// https://www.beecrowd.com.br/judge/pt/problems/view/2893

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define MOD 1000007

typedef unsigned uint;
typedef long long ll;

int main() { _
    vector<ll> prefix_sum {0, 1};
    uint k, n; cin >> k >> n;
    uint sum_to_k {1};
    for (uint i {2}; i < k; i++)
        prefix_sum.push_back(i - 1);

    if (n < k) {
        cout << prefix_sum[n] << endl;
        return 0;
    }

    for (uint i {2}; i < k; i++)
        prefix_sum[i] += prefix_sum[i - 1];
    prefix_sum.push_back(2 * prefix_sum[k - 1]);

    for (uint i {k + 1}; i <= n; i++)
        prefix_sum.push_back((prefix_sum[i - 1] - prefix_sum[i - k - 1]) % MOD);

    cout << prefix_sum[n] << endl;
    
    return 0;
}
