/*------------------------------------------------------------------
Tema: Tree & PD --- Algoritmo de Kadane
Nome: Eduardo Costa de Souza
link beecrowd: https://judge.beecrowd.com/pt/problems/view/2333
--------------------------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

int main() { _
    uint n; cin >> n;
    vector<int> fatias(n);
    int sum_fatias {0};
    for (auto &fatia : fatias) {
        cin >> fatia;
        sum_fatias += fatia;
    }

    int max_sum {0}, current_max {0};
    int min_sum {0}, current_min {0};

    for (auto fatia : fatias) {
        current_max = max(0, current_max + fatia);
        max_sum = max(max_sum, current_max);
        current_min = min(0, current_min + fatia);
        min_sum = min(min_sum, current_min);
    }

    cout << max(max_sum, sum_fatias - min_sum) << endl;

    return 0;
}
