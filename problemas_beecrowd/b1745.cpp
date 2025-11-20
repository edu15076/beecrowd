// https://www.beecrowd.com.br/judge/pt/problems/view/1745

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;
typedef unsigned long long ull;
typedef long long ll;

class Solution {
public:
    Solution(string &s) : s(s), sLen(s.length()), memo(s.length() + 1, vector<ull>(3, 0)) {
        fillMemo();
    }

    ull countNumberOfValidSequences() {
        ull sum {0};
        for (uint i {0}; i < sLen; i++)
            sum += memo[i][0];
        return sum;
    }

private:
    string &s;
    vector<vector<ull>> memo;
    uint sLen;

    void fillMemo() {
        for (int i = sLen - 1; i >= 0; i--) {
            if (not isdigit(s[i]))
                continue;
            for (uint mod {0}; mod < 3; mod++)
                memo[i][(s[i] - '0' + mod) % 3] = memo[i + 1][mod];
            memo[i][(s[i] - '0') % 3]++;
        }
    }
};

int main() { _
    string s; cin >> s;
    cout << Solution(s).countNumberOfValidSequences() << endl;

    return 0;
}
