// https://www.beecrowd.com.br/judge/pt/problems/view/2243

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

vector<vector<bool>> m_memo;

bool isSubSetSum(const vector<int>& p, int n, int c) {
    for(int i {0}; i <= n; i++)
        m_memo[i][0] = true;

    for (int j {1}; j <= c; j++)
        m_memo[0][j] = false;

    for (int i {1}; i <= n; i++)
        for (int j {1}; j <= c; j++)
            if (j < p[i - 1])
                m_memo[i][j] = m_memo[i - 1][j];
            else
                m_memo[i][j] = m_memo[i - 1][j] or m_memo[i - 1][j - p[i - 1]];

    return m_memo[n][c];
}

int main() { _
    
    
    return 0;
}
