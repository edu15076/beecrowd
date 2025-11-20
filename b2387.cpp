// https://www.beecrowd.com.br/judge/pt/problems/view/2387

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

int main() { _
    uint n; cin >> n;
    vector<pair<uint, uint>> consultas(n);

    for (auto& [fim, inicio] : consultas)
        cin >> inicio >> fim;

    sort(consultas.begin(), consultas.end());

    uint consultasMantidas {0};
    uint fimAnterior {0};

    for (auto [fim, inicio] : consultas)
        if (inicio >= fimAnterior) {
            consultasMantidas++;
            fimAnterior = fim;
        }

    cout << consultasMantidas << endl;

    return 0;
}
