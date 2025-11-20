#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

int findGreatestRectangle(const vector<int>& v) {
    const int n = v.size();
    vector<int> leftSmall(n, -1), rightSmall(n, n);
    stack<int> s;
    s.push(-1);
    s.push(0);

    for (int i {1}; i < n; s.push(i), ++i) {
        while (v[s.top()] > v[i]) {
            rightSmall[s.top()] = i;
            s.pop();
        }

        if (v[i] != v[i - 1])
            leftSmall[i] = s.top();
        else
            leftSmall[i] = leftSmall[i - 1];
    }

    int maxRect {0};
    for (int i {0}; i < n; ++ i)
        if (const int base = rightSmall[i] - leftSmall[i] - 1, height = v[i]; base and height)
            maxRect = max(maxRect, base * height + base + height + 1);

    return maxRect;
}

int findGreatestSubSuperFunMatrixSize(const vector<vector<int>>& matrix) {
    const int l = static_cast<int>(matrix.size()), c = static_cast<int>(matrix[0].size());

    vector prefixSumMatrix(l, vector(c, 0));

    for (int i {l - 2}; i >= 0; --i)
        for (int j {c - 2}; j >= 0; --j)
            if (matrix[i][j] + matrix[i + 1][j + 1] <= matrix[i][j + 1] + matrix[i + 1][j])
                prefixSumMatrix[i][j] = prefixSumMatrix[i + 1][j] + 1;

    int maxSubMatrix = 0;

    for (int i {0}; i < l - 1; ++i)
        maxSubMatrix = max(maxSubMatrix, findGreatestRectangle(prefixSumMatrix[i]));

    return max(maxSubMatrix, c);
}

int main() { _
    int l, c; cin >> l >> c;

    vector matrix(l, vector<int>(c));

    for (auto& line : matrix)
        for (auto& item : line)
            cin >> item;

    cout << findGreatestSubSuperFunMatrixSize(matrix) << endl;

    return 0;
}
