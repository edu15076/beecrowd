// https://www.beecrowd.com.br/judge/pt/problems/view/2230

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 0xfffffff7

typedef unsigned uint;

vector<uint> findPossibleVisits(const vector<vector<uint>> cidades, uint cidadeInicial, uint maxPedagios) {
    queue<uint> q;
    q.push(cidadeInicial);

    vector<uint> dist(cidades.size(), INF);
    dist[cidadeInicial] = 0;

    while (not q.empty()) {
        auto c = q.front();
        q.pop();

        if (dist[c] == maxPedagios)
            continue;

        for (auto next : cidades[c])
            if (dist[next] == INF) {
                dist[next] = dist[c] + 1;
                q.push(next);
            }
    }

    vector<uint> cidadesPossiveis;
    for (uint i {0}, len = (uint) dist.size(); i < len; i++)
        if (dist[i] > 0 and dist[i] <= maxPedagios)
            cidadesPossiveis.push_back(i + 1);
    return cidadesPossiveis;
}

int main() { _
    uint c, e, l, p;
    for (uint test {1}; cin >> c >> e >> l >> p and c and e and l and p; test++) {
        l--;
        vector<vector<uint>> cidades(c);
        while (e--) {
            uint x, y; cin >> x >> y; x--; y--;
            cidades[x].push_back(y);
            cidades[y].push_back(x);
        }

        cout << "Teste " << test << endl;
        auto cidadesPossiveis = findPossibleVisits(cidades, l, p);
        for (auto cidade : cidadesPossiveis)
            cout << cidade << ' ';
        cout << endl << endl;
    }
    
    return 0;
}
