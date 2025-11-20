// https://www.beecrowd.com.br/judge/pt/problems/view/1750

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 1'000'000'000
#define dif(a, b) min(abs(a - b), 24 - abs(a - b))

typedef unsigned uint;
typedef unsigned short ushort;

int main() { _
    uint n; cin >> n;
    vector<short> fusos(n);
    for (auto &fuso : fusos)
        cin >> fuso;
    sort(fusos.begin(), fusos.end());

    uint min_dif_pair_12 {0};
    for (auto it = fusos.begin(); it < fusos.end() - 1; it += 2)
        min_dif_pair_12 += dif(*it, *(it + 1));

    uint min_dif_pair_n1 = dif(*fusos.begin(), *fusos.rbegin());
    for (auto it = fusos.begin() + 1; it < fusos.end() - 2; it += 2)
        min_dif_pair_n1 += dif(*it, *(it + 1));

    cout << min(min_dif_pair_n1, min_dif_pair_12) << endl;

    return 0;
}
