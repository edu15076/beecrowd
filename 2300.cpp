// https://www.beecrowd.com.br/judge/pt/problems/view/2295

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

void passarPorEstacoes(vector<vector<uint>>& estacoes, vector<bool>& visitadas, uint curr) {
    visitadas[curr] = true;

    for (auto estacao : estacoes[curr])
        if (not visitadas[estacao])
            passarPorEstacoes(estacoes, visitadas, estacao);
}

bool doAndInList(const vector<bool> l) {
    for (auto item : l)
        if (not item)
            return false;
    return true;
}

int main() { _
    int e, l;

    for (uint testCase {1}; cin >> e >> l and e and l; testCase++) {
        vector<vector<uint>> estacoes(e);

        while (l--) {
            uint x, y; cin >> x >> y; x--; y--;
            estacoes[x].push_back(y);
            estacoes[y].push_back(x);
        }

        vector<bool> visitadas(e, false);
        passarPorEstacoes(estacoes, visitadas, 0);

        cout << "Teste " << testCase << endl;
        if (doAndInList(visitadas))
            cout << "normal";
        else
            cout << "falha";
        cout << "\n\n";
    }
    
    return 0;
}
