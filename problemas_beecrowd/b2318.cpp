// https://www.beecrowd.com.br/judge/pt/problems/view/2318

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned short ushort;

int main() { _
    vector<vector<ushort>> quad(3, vector<ushort>(3));
    vector<pair<ushort, ushort>> mid, diag;
    for (ushort i {0}; i < 3; ++i)
        for (ushort j {0}; j < 3; ++j) {
            cin >> quad[i][j];
            if (not quad[i][j] and (i != j or i != 1)) {
                if (i == j or i == 2 - j)
                    diag.emplace_back(i, j);
                else
                    mid.emplace_back(i, j);
            }
        }

    for (ushort i {0}; not quad[1][1] and i < 3; ++i) // se quad[1][1] = 0 existem mais dois valores 0
        if (quad[0][i] and quad[2][2 - i])
            quad[1][1] = (quad[0][i] + quad[2][2 - i]) / 2;

    ushort soma = quad[1][1] * 3;

    for (auto [i, j] : diag) {
        quad[i][j] = soma;
        if (quad[2 - i][2 - j])
            quad[i][j] -= quad[1][1] + quad[2 - i][2 - j];
        else if (quad[1][j] and quad[2 - i][j])
            quad[i][j] -= quad[1][j] + quad[2 - i][j];
        else
            quad[i][j] -= quad[i][2 - j] + quad[i][1];
    }

    for (auto [i, j] : mid) {
        const bool coluna = i & 1; // se o meio eh de uma coluna
        const bool linha {not coluna};
        quad[i][j] = soma - quad[i + coluna][j + linha] - quad[i - coluna][j - linha];
    }

    for (auto& line : quad) {
        for (auto it = line.begin(); it != line.end() - 1; ++it)
            cout << *it << ' ';
        cout << *line.rbegin() << endl;
    }

    return 0;
}
