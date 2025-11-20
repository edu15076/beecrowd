// https://judge.beecrowd.com/pt/problems/view/2367

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

class Competition {
public:
    vector<int> memo;

    Competition(uint n, uint m) : memo(n + 1, 0) {
        for (int i {0}; i <= n; i++)
            if (not memo[i])
                for (int j {i + 1}; j - i <= m and j <= n; j++)
                    memo[j] = not memo[j] ? j - i : -1;
            else if (memo[i] > 0 and i + memo[i] <= n)
                memo[i + memo[i]] = not memo[i + memo[i]] ? memo[i] : -1;
    }

    bool get_result() {
        return memo.back();
    }
};

int main() { _
    uint n, m; cin >> n >> m;
    cout << (Competition(n, m).get_result() ? "Paula" : "Carlos") << endl;

    return 0;
}
