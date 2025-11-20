// https://www.beecrowd.com.br/judge/pt/problems/view/1767

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define MAX_PESO 50

vector<vector<tuple<int, int, int>>> m_memo;

tuple<int, int, int> backpack_rec(int pacoteIdx, int pesoLivre, const vector<pair<int, int>>& pacotes) {
    if (pacoteIdx == pacotes.size())
        return {0, MAX_PESO - pesoLivre, 0};

    if (get<0>(m_memo[pacoteIdx][pesoLivre]) != -1)
        return m_memo[pacoteIdx][pesoLivre];
    
    auto [qt, peso] = pacotes[pacoteIdx];

    auto deixando = backpack_rec(pacoteIdx + 1, pesoLivre, pacotes);
    get<2>(deixando)++;
    
    if (pesoLivre < peso)
        return m_memo[pacoteIdx][pesoLivre] = deixando;

    auto pegando = backpack_rec(pacoteIdx + 1, pesoLivre - peso, pacotes);
    get<0>(pegando) += qt;

    if (get<0>(pegando) > get<0>(deixando))
        return m_memo[pacoteIdx][pesoLivre] = pegando;
    return m_memo[pacoteIdx][pesoLivre] = deixando;
}

tuple<int, int, int> selecionarPacotes(const vector<pair<int, int>>& pacotes) {
    return backpack_rec(0, MAX_PESO, pacotes);
}

int main() { _
    int n; cin >> n;

    while (n--) {
        int pac; cin >> pac;
        vector<pair<int, int>> pacotes(pac);
        for (auto& [qt, peso] : pacotes)
            cin >> qt >> peso;

        m_memo = vector(pac, vector<tuple<int, int, int>>(51, {-1, -1, -1}));

        auto [brinquedos, peso, sobra] = selecionarPacotes(pacotes);
        cout << brinquedos << " brinquedos" << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "sobra(m) " << sobra << " pacote(s)" << endl;
        cout << endl;
    }
    
    return 0;
}
