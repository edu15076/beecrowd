// https://www.beecrowd.com.br/judge/pt/problems/view/2309

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

int compararCartas(uint x, uint y) {
    static unordered_map<uint, uint> cartas {
            {1, 8},
            {2, 9},
            {3, 10},
            {4, 1},
            {5, 2},
            {6, 3},
            {7, 4},
            {11, 6},
            {12, 5},
            {13, 7}
    };

    return cartas[x] - cartas[y];
}

char calcularVencedorRodada(uint a, uint b) {
    if (compararCartas(a, b) < 0)
        return 'B';
    return 'A';
}

char calcularVencedorPartida(tuple<uint, uint, uint> a, tuple<uint, uint, uint> b) {
     vector<char> vencedores {calcularVencedorRodada(get<0>(a), get<0>(b)),
                              calcularVencedorRodada(get<1>(a), get<1>(b)),
                              calcularVencedorRodada(get<2>(a), get<2>(b))};

    if (count(vencedores.begin(), vencedores.end(), 'A') >= 2)
        return 'A';
    return 'B';
}

int main() { _
    uint n; cin >> n;

    uint vitoriasA {0}, vitoriasB {0};

    while (n--) {
        tuple<uint, uint, uint> a, b;
        cin >> get<0>(a) >> get<1>(a) >> get<2>(a) >> get<0>(b) >> get<1>(b) >> get<2>(b);
        bool bGanhou = calcularVencedorPartida(a, b) - 'A';
        vitoriasA += not bGanhou;
        vitoriasB += bGanhou;
    }

    cout << vitoriasA << " " << vitoriasB << endl;
    
    return 0;
}
