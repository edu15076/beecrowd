// https://www.beecrowd.com.br/judge/pt/problems/view/2308

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 1'000'000

typedef unsigned uint;

uint shortestLoopDistance(const vector<vector<pair<uint, uint>>>& graph, uint start) {
    vector<uint> weight(graph.size(), INF);

    priority_queue<pair<int, uint>, vector<pair<int, uint>>, greater<>> priorityQueue;
    priorityQueue.emplace(0, start);

    for (uint i {0}; not priorityQueue.empty(); i++) {
        auto [w, v] = priorityQueue.top();
        priorityQueue.pop();

        for (auto [u, t] : graph[v])
            if (w + t < weight[u]) {
                priorityQueue.emplace(w + t, u);
                weight[u] = w + t;
            }
    }

    return weight[start];
}

int main() { _
    uint s, c; cin >> s >> c;
    vector<uint> temposPorSala(s);
    for (auto& tempoSala : temposPorSala)
        cin >> tempoSala;

    vector<vector<pair<uint, uint>>> museu(s);

    while (c--) {
        uint i, f, t; cin >> i >> f >> t; i--; f--;
        museu[i].emplace_back(f, t + temposPorSala[i]);
    }

    vector<uint> time(s, INF);

    for (uint i {0}; i < s; i++)
        time[i] = shortestLoopDistance(museu, i);

    cout << *min_element(time.begin(), time.end()) << endl;

    return 0;
}
