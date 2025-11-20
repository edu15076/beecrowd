// https://www.beecrowd.com.br/judge/pt/problems/view/2303

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
};

int main() { _
    uint l, c, m, n; cin >> l >> c >> m >> n;

    vector<vector<uint>> cajueiros(l, vector<uint>(c));

    for (auto& line : cajueiros)
        for (auto& cajus : line)
            cin >> cajus;

    vector<PrefixSum> cajueirosPS;

    for (uint i {0}; i < l; ++i)
        cajueirosPS.emplace_back(cajueiros[i]);

    uint maxCajus {0};

    for (uint j {0}; j < c - n + 1; j++) {
        uint somaAnterior {0};
        for (uint i {0}; i < m; i++)
            somaAnterior += cajueirosPS[i].get(j, j + n - 1);
        maxCajus = max(maxCajus, somaAnterior);
        for (uint i {1}; i < l - m + 1; i++) {
            somaAnterior = somaAnterior + cajueirosPS[i + m - 1].get(j, j + n - 1) - cajueirosPS[i - 1].get(j, j + n - 1);
            maxCajus = max(maxCajus, somaAnterior);
        }
    }

    cout << maxCajus << endl;
    
    return 0;
}
