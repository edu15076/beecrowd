#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 100000

typedef unsigned uint;

void findAllMinDistancesPassingByK(vector<vector<uint>>& distances, uint size, uint k) {
    for (uint i {0}; i < size; ++i)
        for (uint j {0}; j < size; ++j)
            distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
}

void findAllMinDistances(vector<vector<uint>>& distances, uint size) {
    for (uint k {0}; k < size; ++k)
        findAllMinDistancesPassingByK(distances, size, k);
}

int main() { _
    uint n, m; cin >> n >> m;
    vector<vector<uint>> distances(n, vector<uint>(n, INF));

    for (uint i {0}; i < m; ++i) {
        uint u, v, w; cin >> u >> v >> w;
        distances[u][v] = distances[v][u] = min(w, distances[u][v]);
    }

    for (uint i {0}; i < n; ++i)
        distances[i][i] = 0;

    findAllMinDistances(distances, n);

    uint minMaxDistance {INF};

    for (auto& distancesToK : distances)
        minMaxDistance = min(*max_element(distancesToK.begin(), distancesToK.end()), minMaxDistance);

    cout << minMaxDistance << endl;

    return 0;
}
