// https://www.beecrowd.com.br/judge/pt/problems/view/2446

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

bool is_subset_sum(const vector<int>& p, int n, int c) {
    vector memo(n + 1, vector<bool>(c + 1, false));
    for (auto &line : memo)
        line[0] = true;

    for (int i {1}; i <= n; i++) {
        for (int j{1}; j <= c; j++)
            if (j < p[i - 1])
                memo[i][j] = memo[i - 1][j];
            else
                memo[i][j] = memo[i - 1][j] or memo[i - 1][j - p[i - 1]];
    }

    return memo[n][c];
}

int main() { _
    int v, m; cin >> v >> m;
    vector<int> coins(m);
    for (auto &coin : coins)
        cin >> coin;
    cout << (is_subset_sum(coins, m, v) ? 'S' : 'N') << endl;
    
    return 0;
}
