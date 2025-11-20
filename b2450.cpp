// https://www.beecrowd.com.br/judge/pt/problems/view/2450

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

void writeMatrix(vector<vector<int>>& matrix, const int n, const int m) {
    matrix = vector<vector<int>>(n, vector<int>(m));
    for (int i {0}; i < n; i++)
        for (int j{0}; j < m; j++)
            cin >> matrix[i][j];
}

bool isEscada(const vector<vector<int>>& matrix) {
    const int n = (int) matrix.size(), m = (int) matrix[0].size();
    int qtdZeros {-1};
    for (int i {0}; i < n; i++)
        for (int j{0}; j < m; j++) {
            if (matrix[i][j]) {
                if (j > qtdZeros) {
                    qtdZeros = j;
                    break;
                }
                return false;
            }

            if (j == m - 1)
                qtdZeros = j;
        }
    return true;
}

int main() { _
    int n, m; cin >> n >> m;
    vector<vector<int>> matrix;
    writeMatrix(matrix, n, m);

    cout << (isEscada(matrix) ? 'S' : 'N') << endl;
    
    return 0;
}
