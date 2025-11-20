// https://www.beecrowd.com.br/judge/pt/problems/view/3044

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 0xfffffff0
    
typedef unsigned uint;

uint mDfsArticulationVertexes(const vector<vector<uint>>& adj, vector<bool>& visited, vector<uint>& depth,
                              vector<uint>& low, set<uint>& articulationVertexes, uint v = 0, uint d = 0) {
    visited[v] = true;
    depth[v] = low[v] = d;

    uint children {0};

    for (auto u : adj[v]) {
        if (depth[u] == depth[v] - 1)
            continue;

        if (not visited[u]) {
            d = mDfsArticulationVertexes(adj, visited, depth, low, articulationVertexes, u, d + 1);
            ++children;
            low[v] = min(low[v], low[u]);
            if (low[u] >= depth[v] and (v or children > 1))
                articulationVertexes.insert(v);
        } else
            // Quando chega em um que já foi visitado, então existe um caminho alternativo. Queremos o caminho alternativo
            // que volte o máximo possível
            low[v] = min(low[v], depth[u]);
    }

    return d;
}

set<uint> dfsArticulationVertexes(const vector<vector<uint>>& g) {
    const uint n = g.size();
    vector<bool> visited(n, false);
    vector<uint> depth(n, INF), low(n, INF);
    set<uint> articulationVertexes;
    mDfsArticulationVertexes(g, visited, depth, low, articulationVertexes);
    return articulationVertexes;
}

int main() { _
    uint n, m;

    for (uint test {1}; cin >> n >> m and n; test++) {
        vector<vector<uint>> topologia(n);

        while (m--) {
            uint x, y; cin >> x >> y; x--; y--;
            topologia[x].push_back(y);
            topologia[y].push_back(x);
        }

        set<uint> needReplaceComputers = dfsArticulationVertexes(topologia);

        cout << "Teste " << test << endl;

        if (needReplaceComputers.empty()) {
            cout << "nenhum" << endl << endl;
            continue;
        }

        for (auto computer : needReplaceComputers)
            cout << (computer + 1) << " ";
        cout << endl << endl;
    }
    
    return 0;
}
