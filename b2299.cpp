// https://www.beecrowd.com.br/judge/pt/problems/view/2299

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

class Backpack {
public:
    Backpack(uint backpack_size, vector<pair<uint, uint>> &pacotes) : pacotes(pacotes),
            memo(pacotes.size(), vector<int>(backpack_size + 1, -1)) {
        fill_memo(0, backpack_size);
    }

    uint solve() {
        return memo[0][memo[0].size() - 1];
    }

private:
    vector<vector<int>> memo;
    vector<pair<uint, uint>> &pacotes;

    uint fill_memo(uint i, uint space_left) {
        if (i == pacotes.size())
            return 0;

        if (memo[i][space_left] != -1)
            return memo[i][space_left];

        auto [w, q] = pacotes[i];
        if (space_left < w)
            return memo[i][space_left] = fill_memo(i + 1, space_left);
        return memo[i][space_left] = max(fill_memo(i + 1, space_left - w) + q, fill_memo(i + 1, space_left));
    }
};

int main() { _
    for (uint c, f, teste {1}; cin >> c >> f and c; teste++) {
        vector<pair<uint, uint>> pacotes(f);
        for (auto &[w, q] : pacotes)
            cin >> w >> q;

        cout << "Teste " << teste << endl;
        cout << Backpack(c, pacotes).solve() << endl;
        cout << endl;
    }
    
    return 0;
}
