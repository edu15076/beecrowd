// https://www.beecrowd.com.br/judge/pt/problems/view/2429

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

void dfs(const vector<vector<uint>> &g, vector<bool>& visited) {
    stack<uint> stk;
    stk.push(0);

    while (not stk.empty()) {
        auto v = stk.top();
        stk.pop();

        for (auto u : g[v])
            if (not visited[u]) {
                visited[u] = true;
                stk.push(u);
            }
    }
}

bool big_and(const vector<bool> &v) {
    for (auto item : v)
        if (not item)
            return false;
    return true;
}

int main() { _
    uint n; cin >> n;
    vector<vector<uint>> g(n);
    vector<bool> visited(n, false);

    bool works {true};

    while (n--) {
        uint a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
    }

    dfs(g, visited);

    cout << (big_and(visited) ? 'S' : 'N') << endl;
    
    return 0;
}
