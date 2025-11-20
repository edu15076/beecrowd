// https://www.beecrowd.com.br/judge/pt/problems/view/2884

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define MAX_PASSOS 1'000

typedef unsigned uint;

int count_passos(set<uint> &bulbs_on, const vector<vector<uint>> &switches) {
    for (uint passos {0}; passos < MAX_PASSOS; passos++) {
        uint light_switch = passos % switches.size();
        for (auto &bulb : switches[light_switch])
            if (bulbs_on.contains(bulb))
                bulbs_on.erase(bulb);
            else
                bulbs_on.insert(bulb);
        if (bulbs_on.empty())
            return passos + 1;
    }

    return -1;
}

int main() { _
    uint n, m; cin >> n >> m;
    uint l; cin >> l;

    set<uint> bulbs_on;
    while (l--) {
        uint bulb; cin >> bulb;
        bulbs_on.insert(bulb);
    }

    vector<vector<uint>> switches(n);
    for (auto &light_switch : switches) {
        uint k; cin >> k;
        while (k--) {
            uint bulb; cin >> bulb;
            light_switch.push_back(bulb);
        }
    }

    cout << count_passos(bulbs_on, switches) << endl;

    return 0;
}
