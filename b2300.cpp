// https://www.beecrowd.com.br/judge/pt/problems/view/2300

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

void dfs(int u, vector<bool>& v, const vector<vector<int>>& g) {
    stack<int> stk;
    stk.push(u);

    while (not stk.empty()) {
        u = stk.top();
        stk.pop();
        v[u] = true;

        for (auto w: g[u])
            if (not v[w])
                stk.push(w);
    }
}

bool ehTudoVerdadeiro(vector<bool>& v) {
    for (auto item : v)
        if (not item)
            return false;
    return true;
}

int main() { _
    int e, l;
    for (int teste {1}; cin >> e >> l and e and l; teste++) {
        vector<vector<int>> estacoes(e);

        while (l--) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            estacoes[x].push_back(y);
            estacoes[y].push_back(x);
        }

        vector<bool> v(e, false);
        dfs(0, v, estacoes);

        cout << "Teste " << teste << endl;
        cout << (ehTudoVerdadeiro(v) ? "normal" : "falha") << endl;
        cout << endl;
    }
    
    return 0;
}
