// https://www.beecrowd.com.br/judge/pt/problems/view/2460

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main() { _
    int n; cin >> n;
    vector<int> fila(n);

    for (int i {0}; i < n; i++) {
        int id; cin >> id;
        fila[i] = id;
    }

    int m; cin >> m;
    unordered_set<int> sairamDaFila;

    for (int i {0}; i < m; i++) {
        int id; cin >> id;
        sairamDaFila.insert(id);
    }

    vector<int> filaFinal;
    for (auto pessoa : fila)
        if (!sairamDaFila.contains(pessoa))
            filaFinal.push_back(pessoa);

    int maxIndex = (int) filaFinal.size() - 1;
    for (int i {0}; i < maxIndex; i++)
        cout << filaFinal[i] << " ";
    cout << filaFinal[maxIndex] << endl;
    
    return 0;
}
