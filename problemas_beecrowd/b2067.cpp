// https://www.beecrowd.com.br/judge/pt/problems/view/2067

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

class PrefixSum {
public:
    vector<uint> s;

    explicit PrefixSum(const vector<uint>& base) {
        s = vector<uint>(base.size());
        s[0] = base[0];

        for (uint i {1}; i < s.size(); i++)
            s[i] = s[i - 1] + base[i];
    }

    uint get(uint start, uint end) {
        return start ? s[end] - s[start - 1] : s[end];
    }

    uint get(uint pos) {
        return get(0, pos);
    }

    uint size() {
        return s.size();
    }
};

bool has_zero(PrefixSum &prefix_sum, uint first, uint last) {
    return last - first + 1 != prefix_sum.get(first, last);
}

bool is_doable(vector<PrefixSum> &matrix, uint square_side) {
    for (uint i {0}; i + square_side - 1 < matrix[0].size(); i++) {
        uint doable_sequence {0};
        for (auto &line : matrix) {
            if (not has_zero(line, i, i + square_side - 1))
                doable_sequence++;
            else
                doable_sequence = 0;
            if (doable_sequence == square_side)
                return true;
        }
    }
    return false;
}

int main() { _
    uint n, m; cin >> n >> m;
    vector<vector<uint>> base_matrix(n, vector<uint>(m));
    for (auto &line : base_matrix)
        for (auto &item : line) {
            cin >> item;
            if (item)
                item = 1;
        }

    vector<PrefixSum> matrix;

    for (auto &line : base_matrix)
        matrix.emplace_back(line);

    uint q; cin >> q;
    while (q--) {
        uint square_side; cin >> square_side;
        cout << (is_doable(matrix, square_side) ? "yes" : "no") << endl;
    }
    
    return 0;
}
