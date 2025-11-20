// https://www.beecrowd.com.br/judge/pt/problems/view/3052

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

int main() { _
    uint n, m; cin >> n >> m;

    vector parede(n + 2, vector<char>(m + 2, 0));

    for (uint i {1}; i <= n; ++i)
        for (uint j {1}; j <= m; ++j)
            cin >> parede[i][j];

    for (uint i {1}; i <= n; ++i) {
        for (uint j {1}; j <= m; ++j)
            if (parede[i][j] == '.' and
                    (parede[i - 1][j] == 'o' or
                    parede[i][j - 1] == 'o' and parede[i + 1][j - 1] == '#' or
                    parede[i][j + 1] == 'o' and parede[i + 1][j + 1] == '#'))
                parede[i][j] = 'o';
        for (uint j {m}; j >= 1; --j)
            if (parede[i][j] == '.' and
                (parede[i - 1][j] == 'o' or
                 parede[i][j - 1] == 'o' and parede[i + 1][j - 1] == '#' or
                 parede[i][j + 1] == 'o' and parede[i + 1][j + 1] == '#'))
                parede[i][j] = 'o';
    }

    for (uint i {1}; i <= n; ++i) {
        for (uint j {1}; j <= m; ++j)
            cout << parede[i][j];
        cout << endl;
    }
    
    return 0;
}
