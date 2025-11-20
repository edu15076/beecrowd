// https://www.beecrowd.com.br/judge/pt/problems/view/2455

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main() { _
    int p1, c1, p2, c2;
    cin >> p1 >> c1 >> p2 >> c2;
    int dif {p2 * c2 - p1 * c1};
    cout << (dif >> 31 | !!dif) << endl;
    return 0;
}
