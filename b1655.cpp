// https://www.beecrowd.com.br/judge/pt/problems/view/1655

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

vector<double> compute_percentages(uint start, const vector<vector<pair<double, uint>>> &g) {
    vector<double> percentages(g.size(), 0.0);
    priority_queue<pair<double, uint>> pq;
    pq.emplace(1.0, start);
    percentages[start] = 1.0;

    while (not pq.empty()) {
        auto [vw, v] = pq.top(); pq.pop();

        if (vw < percentages[v])
            continue;

        percentages[v] = vw;

        for (auto [uw, u] : g[v])
            if (uw * vw > percentages[u])
                pq.emplace(uw * vw, u);
    }

    return percentages;
}

double calculate_max_percentage(const vector<vector<pair<double, uint>>> &g) {
    return compute_percentages(0, g)[g.size() - 1];
}

int main() { _
    uint n, m;
    cout << fixed << setprecision(6);

    while (cin >> n and n) {
        cin >> m;
        vector<vector<pair<double, uint>>> g(n);

        while (m--) {
            uint a, b; cin >> a >> b; a--; b--;
            double p; cin >> p; p /= 100;
            g[a].emplace_back(p, b);
            g[b].emplace_back(p, a);
        }

        cout << calculate_max_percentage(g) * 100 << " percent" << endl;
    }
    
    return 0;
}
