// https://www.beecrowd.com.br/judge/pt/problems/view/1929

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main() { _
    vector<int> lados;
    for (int i {0}; i < 4; i++) {
        int input; cin >> input;
        lados.push_back(input);
    }

    sort(lados.begin(), lados.end());

    if (lados[0] + lados[1] > lados[2] || lados[1] + lados[2] > lados[3])
        cout << 'S' << endl;
    else
        cout << 'N' << endl;

    return 0;
}
