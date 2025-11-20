// https://www.beecrowd.com.br/judge/pt/problems/view/2676

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

uint sum(const vector<uint> v) {
    uint s {0};
    for (auto item : v)
        s += item;
    return s;
}

vector<uint> compute_distances(uint start, const vector<vector<pair<uint, uint>>> &g) {
    vector<uint> distances(g.size(), UINT32_MAX);
    priority_queue<pair<uint, uint>, vector<pair<uint, uint>>, greater<>> pq;
    pq.emplace(0, start);
    distances[start] = 0;

    while (not pq.empty()) {
        auto [vw, v] = pq.top(); pq.pop();

        if (vw >= distances[v] and vw)
            continue;

        distances[v] = vw;

        for (auto [uw, u] : g[v])
            if (uw + vw < distances[u])
                pq.emplace(uw + vw, u);
    }

    return distances;
}

int main() { _
    uint n, r;

    while (cin >> n >> r and n and r) {
        vector<vector<pair<uint, uint>>> g(n);

        while (r--) {
            uint a, b, d; cin >> a >> b >> d; a--; b--;
            g[a].emplace_back(d, b);
            g[b].emplace_back(d, a);
        }

        vector<uint> distances(n);

        for (uint i {0}; i < n; i++)
            distances[i] = sum(compute_distances(i, g));

        uint min_value = *min_element(distances.begin(), distances.end());

        vector<uint> min_positions;

        for (auto it = distances.begin(); it < distances.end(); it++)
            if (*it == min_value)
                min_positions.push_back(it - distances.begin() + 1);

        for (auto it = min_positions.begin(); it != min_positions.end() - 1; it++)
            cout << *it << " ";
        cout << *min_positions.rbegin() << endl;
    }
    
    return 0;
}
