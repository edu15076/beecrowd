// https://www.beecrowd.com.br/judge/pt/problems/view/1558

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define MAX_NUMBER_SQRT 100

typedef unsigned uint;

int main() { _
    vector<uint> squares(MAX_NUMBER_SQRT + 1);
    for (uint i {0}; i <= MAX_NUMBER_SQRT; i++)
        squares[i] = i * i;

    set<uint> all_possible_sums;
    for (uint i {0}; i <= MAX_NUMBER_SQRT; i++)
        for (uint j {i}; j <= MAX_NUMBER_SQRT; j++)
            all_possible_sums.insert(squares[i] + squares[j]);

    int n;
    while (cin >> n)
        cout << (all_possible_sums.contains(n) ? "YES" : "NO") << endl;
    
    return 0;
}
