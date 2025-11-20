// https://www.beecrowd.com.br/judge/pt/problems/view/3349

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

class Backpack {
public:
    Backpack(uint w) : m_weight(w) {
    }

    int solve(const vector<tuple<int, int, int>>& items) {
        m_memo_ptr = new vector(items.size(), vector(m_weight + 1, -1));
        int solution = m_solve(0, m_weight, items);
        delete m_memo_ptr;
        return solution;
    }

private:
    vector<vector<int>> *m_memo_ptr;
    uint m_weight;

    int m_solve(int item_index, int free_weight, const vector<tuple<int, int, int>>& items) {
        auto &memo = *m_memo_ptr;
        if (item_index == items.size())
            return 0;

        if (memo[item_index][free_weight] != -1)
            return memo[item_index][free_weight];

        auto [quantity, weight, type] = items[item_index];

        auto leaving = m_solve(item_index + 1, free_weight, items);

        if (free_weight < weight)
            return memo[item_index][free_weight] = leaving;

        auto taking = m_solve(item_index + 1, free_weight - weight, items) + quantity;

        if (taking > leaving)
            return memo[item_index][free_weight] = taking;
        return memo[item_index][free_weight] = leaving;
    }
};

int main() { _
    uint h, c, s, p;
    double rational_weight;
    cin >> h >> c >> s >> p >> rational_weight;

    vector<pair<int, int>> bombachas, botas, chapeus, lencos;
    uint free_weight = rational_weight * 10;

    vector<vector<int>> memo(4, vector<int>(10'000 + 1, -1));
    for (auto [quantity, weight] : bombachas)
        memo[0][free_weight - weight] = max(memo[0][free_weight - weight], quantity);

    return 0;
}
