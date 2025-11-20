/*------------------------------------------------------------------
Tema: Tree & PD --- Algoritmo de Kadane
Nome: Eduardo Costa de Souza
link beecrowd: https://judge.beecrowd.com/pt/problems/view/2463
--------------------------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef unsigned uint;

int main() { _
    uint n; cin >> n;
    vector<int> vidas(n);
    for (auto &vida : vidas)
        cin >> vida;

    int max_vidas {0}, max_vidas_atual {0};

    for (auto vida : vidas) {
        max_vidas_atual = max(0, max_vidas_atual + vida);
        max_vidas = max(max_vidas, max_vidas_atual);
    }

    cout << max_vidas << endl;

    return 0;
}
