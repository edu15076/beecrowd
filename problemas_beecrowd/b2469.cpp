// https://www.beecrowd.com.br/judge/pt/problems/view/2469

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef unsigned int uint;

int main() { _
    int n; cin >> n;
    map<uint, uint> notas;

    uint qtdMaior {0}, modaNota;

    for (uint i {0}; i < n; i++) {
        uint nota; cin >> nota;

        if (notas.find(nota) != notas.end())
            notas[nota]++;
        else
            notas[nota] = 1;

        if (notas[nota] > qtdMaior) {
            qtdMaior = notas[nota];
            modaNota = nota;
        } else if (notas[nota] == qtdMaior && nota > modaNota)
            modaNota = nota;
    }

    cout << modaNota << endl;

    return 0;
}
