// https://www.beecrowd.com.br/judge/pt/problems/view/2473

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef unsigned int uint;

template <typename T>
unordered_set<T> inputSet(uint size) {
    unordered_set<T> s(size);
    for (uint i {0}; i < size; i++) {
        T input; cin >> input;
        s.insert(input);
    }
    return s;
}

int main() { _
    unordered_set<int> aposta = inputSet<int>(6);
    int acertos {0};

    for (uint i {0}; i < 6; i++) {
        int sorteio; cin >> sorteio;
        if (aposta.contains(sorteio))
            acertos++;
    }

    switch (acertos) {
        case 3:
            cout << "terno";
            break;
        case 4:
            cout << "quadra";
            break;
        case 5:
            cout << "quina";
            break;
        case 6:
            cout << "sena";
            break;
        default:
            cout << "azar";
    }

    cout << endl;
    
    return 0;
}
