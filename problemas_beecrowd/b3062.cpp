// https://www.beecrowd.com.br/judge/pt/problems/view/3062

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

set<int> vectorBoolToSetOfTruePositions(const vector<bool>& v) {
    set<int> s;

    for (int i {0}, len = (int) v.size(); i < len; ++i)
        if (v[i]) s.insert(i);

    return s;
}

int main() { _
    int n, m; cin >> n >> m;
    vector<unordered_set<int>> upasNaoCombinam(n);

    while (m--) {
        int upa1, upa2; cin >> upa1 >> upa2; upa1--; upa2--;
        if (upa1 > upa2) swap(upa1, upa2);
        upasNaoCombinam[upa2].insert(upa1);
    }

    vector<bool> upas(n, true);

    for (int i {n - 1}; i > 0; --i) {
        if (not upas[i])
            continue;
        for (auto upa : upasNaoCombinam[i])
            upas[upa] = false;
    }

    auto upasSet = vectorBoolToSetOfTruePositions(upas);

    cout << upasSet.size() << endl;

    upasSet.erase(n - 1);

    for (auto upa : upasSet)
        cout << upa + 1 << " ";
    cout << n << endl;
    
    return 0;
}
