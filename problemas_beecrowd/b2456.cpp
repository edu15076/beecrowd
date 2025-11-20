// https://www.beecrowd.com.br/judge/pt/problems/view/2456

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

template <typename T>
void writeVector(vector<T>& v) {
    for (int i {0}; i < v.size(); i++)
        cin >> v[i];
}

int main() { _
    vector<int> cartas(5);
    writeVector(cartas);

    bool crescente = cartas[0] < cartas[1];

    for (int i {1}; i < 4; i++)
        if (crescente != cartas[i] < cartas[i + 1]) {
            cout << 'N' << endl;
            return 0;
        }

    cout << (crescente ? 'C' : 'D') << endl;

    return 0;
}
