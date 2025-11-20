/*------------------------------------------------------------------
Tema: Tree & PD --- Programação dinâmica
Nome: Eduardo Costa de Souza
link beecrowd: https://judge.beecrowd.com/pt/problems/view/2367
--------------------------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define ALWAYS_WIN -1
#define ALWAYS_LOOSE 0

typedef unsigned uint;

class Competition {
public:
    vector<int> memo;

    Competition(uint n, uint m) : memo(n + 1, 0) {
        for (int i {0}; i <= n; i++)
            process(i, n, m);
    }

    bool get_result() {
        return memo.back();
    }

private:
    void process(int i, uint n, uint m) {
        if (memo[i] == ALWAYS_LOOSE)
            for (int j {i + 1}; j - i <= m and j <= n; j++)
                memo[j] = not memo[j] ? j - i : -1;
        else if (memo[i] != ALWAYS_WIN and i + memo[i] <= n)
            memo[i + memo[i]] = not memo[i + memo[i]] ? memo[i] : -1;
    }
};

int main() { _
    uint n, m; cin >> n >> m;
    cout << (Competition(n, m).get_result() ? "Paula" : "Carlos") << endl;

    return 0;
}
