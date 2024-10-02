#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

class Competition {
public:
    vector<tuple<int, bool, bool>> memo;

    Competition(uint n, uint m) : memo(n + 1) {
        memo[0] = {0, false, false};
        memo[1] = {1, true, false};

        for (int i {2}; i <= n; i++)
            memo[i] = compute_best_move(i, m);
    }

    bool get_result() {
        return get<1>(*memo.rbegin());
    }

private:
    tuple<int, bool, bool> compute_best_move(int i, uint m) {
        bool melhor {false}, segunda_melhor {false};
        int melhor_mexida {1};
        for (int j {i - 1}; j >= 0 and i - j <= m; j--)
            if ((get<0>(memo[j]) != i - j and not get<1>(memo[j]))
                or (get<0>(memo[j]) == i - j and not get<2>(memo[j]))) {
                melhor = true;
                melhor_mexida = i - j;
                break;
            }
        for (int j {i - 1}; j >= 0 and i - j <= m; j--)
            if (((get<0>(memo[j]) != i - j and not get<1>(memo[j]))
                 or (get<0>(memo[j]) == i - j and not get<2>(memo[j]))) and i - j != melhor_mexida) {
                segunda_melhor = true;
                break;
            }
        return {melhor_mexida, melhor, segunda_melhor};
    }
};

int main() { _
    uint n, m; cin >> n >> m;
    cout << (Competition(n, m).get_result() ? "Paula" : "Carlos") << endl;

    return 0;
}
