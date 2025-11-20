// https://www.beecrowd.com.br/judge/pt/problems/view/2231

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 10000

typedef unsigned uint;

int main() { _
    uint n, m;
    for (uint teste {1}; cin >> n >> m and n and m; teste++) {
        vector<int> medidas(n);
        for (auto& medida : medidas)
            cin >> medida;

        for (uint i {1}; i < n; i++)
            medidas[i] += medidas[i - 1];
        medidas.push_back(0);

        int minMedia {INF}, maxMedia {-INF};

        for (uint inicio {0}; inicio <= n - m; inicio++) {
            uint fim = inicio + m - 1;
            double media = (double) (medidas[fim] - medidas[(n + inicio) % (n + 1)]) / m;
            if (media < 0 and media != floor(media))
                media++;
            minMedia = min(minMedia, (int) floor(media));
            maxMedia = max(maxMedia, (int) floor(media));
        }

        cout << "Teste " << teste << endl;
        cout << minMedia << " " << maxMedia << endl;
        cout << endl;
    }
    
    return 0;
}
