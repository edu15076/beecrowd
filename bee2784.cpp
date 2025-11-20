/*------------------------------------------------------------------
Tema: Grafos - Dijkstra
Nome: Eduardo Costa de Souza
link beecrowd: https://judge.beecrowd.com/pt/problems/view/2784
--------------------------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

vector<int> d, a;

void dijkstra(const int s, const vector<vector<pair<int, int>>> &g) {
    d = vector(g.size(), 1'000'000'000); d[s] = 0;
    a = vector(g.size(), -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, s);

    while (not pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();

        if (dist > d[u])
            continue;

        for (auto [v, w] : g[u])
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                a[v] = u;
                pq.emplace(d[v], v);
            }
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> ilhas(n);

    for (int i {0}; i < m; i++) {
        int v, u, w; cin >> v >> u >> w; v--; u--;
        ilhas[v].emplace_back(u, w);
        ilhas[u].emplace_back(v, w);
    }

    int s; cin >> s; s--;

    dijkstra(s, ilhas);

    d[s] = *max_element(d.begin(), d.end());

    cout << d[s] - *min_element(d.begin(), d.end()) << endl;

    return 0;
}
