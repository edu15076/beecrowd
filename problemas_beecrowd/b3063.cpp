// https://www.beecrowd.com.br/judge/pt/problems/view/3063

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

#define INF 0x7fffffff

int main() { _
    int t, l, o, d; cin >> t >> l >> o >> d; o--; d--;

    vector<unordered_set<int>> linhas(l);
    vector<vector<int>> terminais(t);

    for (int i = 0; i < l; ++i) {
        int c; cin >> c;
        while (c--) {
            int terminal; cin >> terminal; terminal--;
            linhas[i].insert(terminal);
            terminais[terminal].push_back(i);
        }
    }

    // BFS
    vector<int> distFromOrigin(t, INF);
    distFromOrigin[o] = 0;

    queue<int> q;
    q.push(o);

    while (not q.empty()) {
        auto terminalAtual = q.front();
        q.pop();

        for (auto linhaIndex : terminais[terminalAtual])
            for (auto terminal : linhas[linhaIndex])
                if (distFromOrigin[terminal] == INF) {
                    distFromOrigin[terminal] = distFromOrigin[terminalAtual] + 1;
                    if (terminal == d) {
                        cout << distFromOrigin[d] << endl;
                        return 0;
                    }
                    q.push(terminal);
                }
    }
    
    return 0;
}
