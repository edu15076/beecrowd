// https://www.beecrowd.com.br/judge/pt/problems/view/2392

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

bool podeTerSapo(int pedra, const vector<pair<int, int>>& sapos) {
    for (const auto [p, d] : sapos)
        if (not ((pedra - p) % d))
            return true;
    return false;
}

int main() { _
    int n, m; cin >> n >> m;
    vector<pair<int, int>> sapos(m);

    for (auto& [p, d] : sapos)
        cin >> p >> d;

    for (int i {1}; i <= n; ++i)
        cout << podeTerSapo(i, sapos) << endl;
    
    return 0;
}
