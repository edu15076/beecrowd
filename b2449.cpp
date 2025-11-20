// https://www.beecrowd.com.br/judge/pt/problems/view/2449

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef unsigned int uint;

template <typename T>
vector<T> inputVector(uint size) {
    vector<T> v(size);
    for (uint i {0}; i < size; i++)
        cin >> v[i];
    return v;
}

int main() { _
    int n, m; cin >> n >> m;
    vector<int> pinos = inputVector<int>(n);
    int moves {0};

    for (int i {0}; i < n - 1; i++) {
        int difPino = m - pinos[i];
        moves += abs(difPino);
        pinos[i + 1] += difPino;
    }

    cout << moves << endl;
    
    return 0;
}
