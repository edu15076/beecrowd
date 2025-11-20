// https://www.beecrowd.com.br/judge/pt/problems/view/2384

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define MOD 1'000'000'007
#define NOT_MEMOIZED 1'000'000'007

typedef unsigned uint;
typedef unsigned long long ull;
typedef long long ll;

class Solution {
public:
    Solution(string& n, string& s) : n(n), s(s), sLen(s.length()), nLen(n.length()), memo(s.length() + 1, NOT_MEMOIZED) {
        fillMemo();
    }

    ull countNumberOfValidSequences() {
        return memo[0];
    }

private:
    string& n, s;
    vector<uint64_t> memo;
    uint sLen, nLen;

    inline bool isValid(uint begin, uint end) {
        return end - begin < nLen or (end - begin == nLen and string_view(s.data() + begin, end - begin) <= n);
    }

    ull countNumberOfValidSequencesStartingFrom(uint begin) {
        if (s[begin] == '0')
            return 0;

        ull count {0};

        for (uint end {begin + 1}; end <= sLen; end++) {
            if (not isValid(begin, end))
                break;
            count += memo[end];
        }
        return count % MOD;
    }

    void fillMemo() {
        memo[sLen - 1] = memo[sLen] = 1;

        for (int begin = sLen - 1; begin >= 0; begin--)
            memo[begin] = countNumberOfValidSequencesStartingFrom(begin);
    }
};

int main() { _
    string n, s; cin >> n >> s;

    Solution solution(n, s);

    cout << solution.countNumberOfValidSequences() << endl;

    return 0;
}
