// https://www.beecrowd.com.br/judge/pt/problems/view/2370

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

int main() { _
    unsigned n, t; cin >> n >> t;

    unordered_map<unsigned, string> abilityToName;
    vector<set<string>> times(t);
    priority_queue<unsigned> pq;

    while (n--) {
        string name;
        unsigned ability;
        cin >> name >> ability;

        abilityToName[ability] = name;
        pq.push(ability);
    }

    for (unsigned i {0}; not pq.empty(); i = (i + 1) % t) {
        times[i].insert(abilityToName[pq.top()]);
        pq.pop();
    }

    for (unsigned i {0}; i < t; ++i) {
        cout << "Time " << i + 1 << endl;
        for (auto jogador : times[i])
            cout << jogador << endl;
        cout << endl;
    }

    return 0;
}
