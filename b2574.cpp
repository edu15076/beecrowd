// https://www.beecrowd.com.br/judge/pt/problems/view/2574

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;
typedef unsigned short ushort;

class PrefixSum2D {
public:
    explicit PrefixSum2D(const vector<vector<ushort>>& matrix) {
        ps = vector<vector<uint>>(matrix.size(), vector<uint>(matrix[0].size()));
        mCopyToM(matrix);
        mSumLines();
        mSumColumns();
    }

    size_t size() const {
        return ps.size();
    }

    uint query(uint i, uint j) const {
        return ps[i][j];
    }

    uint queryArea(uint iStart, uint jStart, uint iEnd, uint jEnd) const {
        uint area = query(iEnd, jEnd);
        if (iStart)
            area -= query(iStart - 1, jEnd);
        if (iStart and jStart)
            area += query(iStart - 1, jStart - 1);
        if (jStart)
            area -= query(iEnd, jStart - 1);

        return area;
    }
private:
    vector<vector<uint>> ps;

    void mCopyToM(const vector<vector<ushort>>& matrix) {
        const uint n = matrix.size(), m = matrix[0].size();
        for (uint i {0}; i < n; ++i)
            for (uint j {0}; j < m; j++)
                ps[i][j] = matrix[i][j];
    }

    void mSumLine(uint idx) {
        const uint m = ps[0].size();
        for (uint j {1}; j < m; ++j)
            ps[idx][j] += ps[idx][j - 1];
    }

    void mSumLines() {
        const uint n = ps.size();
        for (uint i {0}; i < n; ++i)
            mSumLine(i);
    }

    void mSumColumn(uint idx) {
        const uint n = ps.size();
        for (uint i {1}; i < n; ++i)
            ps[i][idx] += ps[i - 1][idx];
    }

    void mSumColumns() {
        const uint m = ps[0].size();
        for (uint j {0}; j < m; ++j)
            mSumColumn(j);
    }
};

bool checkAllSumAtLeastToG(const PrefixSum2D& lagoa, uint g, uint side) {
    uint n = lagoa.size();
    for (uint i {side}; i <= n; i += side)
        for (uint j {side}; j <= n; j += side)
            if (lagoa.queryArea(i - side, j - side, i - 1, j - 1) < g)
                return false;
    return true;
}

uint findMinSide(const PrefixSum2D& lagoa, uint g, uint n) {
    for (uint side {1}; side <= n; side <<= 1)
        if (checkAllSumAtLeastToG(lagoa, g, side))
            return side;
    return 0;
}

uint findMaxSquares(const PrefixSum2D& lagoa, uint g, uint n) {
    auto minSide = findMinSide(lagoa, g, n);
    auto qtdSquaresInALine = n / minSide;
    return qtdSquaresInALine * qtdSquaresInALine;
}

int main() { _
    uint n, g; cin >> n >> g;
    vector<vector<ushort>> lagoa(n, vector<ushort>(n));

    for (auto& line : lagoa)
        for (auto& item : line)
            cin >> item;

    auto lagoaPs2d = PrefixSum2D(lagoa);

    cout << findMaxSquares(lagoaPs2d, g, n) << endl;

    return 0;
}
