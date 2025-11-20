// https://www.beecrowd.com.br/judge/pt/problems/view/2228

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

vector dp(101, vector<bool>(5001));

bool isSubSetSum(const vector<int>& p, int n, int c) {
    for(int i {0}; i <= n; i++)
        dp[i][0] = true;

    for (int j {1}; j <= c; j++)
        dp[0][j] = false;

    for (int i {1}; i <= n; i++)
        for (int j {1}; j <= c; j++)
            if (j < p[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - p[i - 1]];

    return dp[n][c];
}

int sum(const vector<int>& v, int n) {
    int r {0};
    for (int i {0}; i < n; ++i)
        r += v[i];
    return r;
}

bool canDivide(int x, int y, vector<int>& joias, int n) {
    int total = sum(joias, n) + x + y;
    if (total & 1)
        return false;

    return isSubSetSum(joias, n, total / 2 - x);
}

int main() { _
    vector<int> joias(100);
    for (int testNum {1}, x, y, n; cin >> x >> y >> n and x and y and n; testNum++) {
        for (int i {0}; i < n; ++i)
            cin >> joias[i];

        cout << "Teste " << testNum << endl;

        cout << (canDivide(x, y, joias, n) ? 'S' : 'N') << endl;
        cout << endl;
    }

    return 0;
}
