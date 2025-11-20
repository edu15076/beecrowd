// https://www.beecrowd.com.br/judge/pt/problems/view/1744

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned long long ull;
typedef long long ll;

class BIT {
public:
    BIT(const size_t n) {
        m_bin = vector<ll>(n + 1, 0);
    }

    void add(size_t pos, ll value) {
        for ( ; pos < m_bin.size(); pos += pos & -pos)
            m_bin[pos] += value;
    }

    ll query(size_t pos) {
        ull sum {0};
        for ( ; pos > 0; pos -= pos & -pos)
            sum += m_bin[pos];
        return sum;
    }
private:
    vector<ll> m_bin;
};

class Solution {
public:
    ull a, b;
    vector<ull> &black_stones, &white_stones;
    BIT &bit;
    vector<vector<ull>> memo;

    Solution(ull a, ull b, vector<ull> &black_stones, vector<ull> &white_stones, BIT &bit) :
            a(a), b(b), black_stones(black_stones), white_stones(white_stones), bit(bit) {
        memo = vector<vector<ull>>(black_stones.size(), vector<ull>(white_stones.size(), -1));
    }

    void swap_stones(size_t black_stone, size_t white_stone) {
        bit.add(white_stone, -1);
        bit.add(black_stone, 1);
    }

    ull solve() {
        return dp(black_stones.size() - 1, 0);
    }
private:
    ull dp(ull preta_idx, ull branca_idx) {
        if (preta_idx == -1 or white_stones[branca_idx] > black_stones[preta_idx] or branca_idx >= white_stones.size())
            return 0;
        if (memo[preta_idx][branca_idx] != -1)
            return memo[preta_idx][branca_idx];

        swap_stones(black_stones[preta_idx], white_stones[branca_idx]);
        ull jump = a + dp(preta_idx - 1, branca_idx + 1);
        swap_stones(white_stones[branca_idx], black_stones[preta_idx]);
        ull swap = dp(preta_idx - 1, branca_idx) + bit.query(black_stones[preta_idx]) * (a - b);
        return memo[preta_idx][branca_idx] = min(jump, swap);
    }
};

int main() {
    ull a, b; cin >> a >> b;
    string stones; cin >> stones;
    vector<ull> black_stones;
    vector<ull> white_stones;
    BIT bit = BIT(stones.size());

    for (auto it = stones.begin(); it != stones.end(); it++) {
        auto stone = *it;
        if (stone == 'W') {
            bit.add(it - stones.begin() + 1, 1);
            white_stones.push_back(it - stones.begin() + 1);
            continue;
        }
        black_stones.push_back(it - stones.begin() + 1);
    }

    cout << Solution(a, b, black_stones, white_stones, bit).solve() << endl;

    return 0;
}
