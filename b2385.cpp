// https://www.beecrowd.com.br/judge/pt/problems/view/2385

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;
typedef unsigned long long ull;

ull multiplyVectors(const vector<uint>& v1, const vector<uint>& v2) {
    ull multiplicationResult {0};

    for (uint i {0}, size = v1.size(); i < size; ++i)
        multiplicationResult += v1[i] * v2[i];

    return multiplicationResult;
}

int main() { _
    uint n; cin >> n;
    uint p, q, r, s, x, y; cin >> p >> q >> r >> s >> x >> y;
    uint i, j; cin >> i >> j;

    vector<uint> lineA(n), columnB(n);

    for (uint k {1}; k <= n; ++k) {
        lineA[k - 1] = (p * i + q * k) % x;
        columnB[k - 1] = (r * k + s * j) % y;
    }

    cout << multiplyVectors(lineA, columnB) << endl;

    return 0;
}
