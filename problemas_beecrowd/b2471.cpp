// https://www.beecrowd.com.br/judge/pt/problems/view/2471

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

template <typename T>
vector<vector<T>> inputMatrix(uint numLines, uint numColumns) {
    vector<vector<T>> m(numLines);
    for (uint i {0}; i < numLines; i++)
        m[i] = inputVector<T>(numColumns);
    return m;
}

uint getDif(vector<int>& v) {
    int m;
    if (v[0] == v[1])
        m = v[0];
    else if (v[0] == v[2])
        return 1;
    else
        return 0;

    for (uint i {2}, len {v.size()}; i < len; i++)
        if (v[i] != m)
            return i;
}

int main() { _
    int n; cin >> n;
    vector<vector<int>> quadrado = inputMatrix<int>(n, n);

    vector<int> sumLines(n, 0), sumColumns(n, 0);
    for (uint i {0}; i < n; i++)
        for (uint j {0}; j < n; j++) {
            sumLines[i] += quadrado[i][j];
            sumColumns[i] += quadrado[j][i];
        }

    pair<uint, uint> difPos {getDif(sumLines), getDif(sumColumns)};
    int m = sumLines[!difPos.first];
    int difSumLine = sumLines[difPos.first];
    int difValue = quadrado[difPos.first][difPos.second];

    cout << difValue + m - difSumLine << ' ' << difValue << endl;

    return 0;
}
