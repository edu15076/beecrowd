// https://www.beecrowd.com.br/judge/pt/problems/view/2288

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second

typedef unsigned uint;

unsigned int mod(int a, int n) {
    return (n + a % n) % n;
}

int main() { _
    for (int n, m, teste_number {1}; cin >> n >> m and n; teste_number++) {
        vector<vector<uint>> matrix(n, vector<uint>(m));

        for (auto &line : matrix)
            for (auto &item : line)
                cin >> item;

        pair<int, int> move {0, 0};

        for (int x, y; cin >> x >> y and (x or y); ) {
            move.x += -x;
            move.y += y;
        }

        cout << "Teste " << teste_number << endl;

        for (int i {0}; i < n; i++) {
            for (int j {0}; j < m - 1; j++)
                cout << matrix[mod(i + move.y, n)][mod(j + move.x, m)] << " ";
            cout << matrix[mod(i + move.y, n)][mod(move.x - 1, m)] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
