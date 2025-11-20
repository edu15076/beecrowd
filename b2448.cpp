// https://www.beecrowd.com.br/judge/pt/problems/view/2448

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main() { _
    int n, m; cin >> n >> m;
    unordered_map<int, int> casaToPos;
    int entradaCasa;

    for (int i {0}; i < n; i++) {
        cin >> entradaCasa;
        casaToPos[entradaCasa] = i;
    }

    cin >> entradaCasa;
    int posCasaBefore = casaToPos[entradaCasa];
    int tempo = casaToPos[entradaCasa];

    for (int i {1}; i < m; i++) {
        cin >> entradaCasa;
        tempo += abs(posCasaBefore - casaToPos[entradaCasa]);
        posCasaBefore = casaToPos[entradaCasa];
    }

    cout << tempo << endl;
    
    return 0;
}
