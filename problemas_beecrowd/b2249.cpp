// https://www.beecrowd.com.br/judge/pt/problems/view/2249

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

vector<string> split(const string& s, const string& pattern) {
    vector<string> splited;
    for (uint i {0}; i < s.length(); ) {
        uint nextPos = s.find(pattern, i);
        splited.push_back(s.substr(i, nextPos - i));
        if (nextPos == UINT32_MAX)
            break;
        i = nextPos + pattern.length();
    }

    return splited;
}

struct OrdNames {
    bool operator()(const string& a, const string& b) const {
        auto aSplited = split(a, ". ");
        auto bSplited = split(b, ". ");

        return aSplited[1] < bSplited[1] or (aSplited[1] == bSplited[1] and aSplited[0] < bSplited[0]);
    }
};

int main() { _
    uint a;

    for (uint test {1}; cin >> a and a; ++test) {
        vector<vector<uint>> artigos(a);

        uint id {0};

        map<string, uint, OrdNames> idPorNome;
        idPorNome["P. Erdos"] = id++;

        string line;
        getline(cin, line);

        for (auto& artigo : artigos) {
            getline(cin, line);
            line = line.substr(0, line.length() - 1);
            auto autores = split(line, ", ");

            for (const auto& autor : autores) {
                if (not idPorNome.contains(autor))
                    idPorNome[autor] = id++;
                artigo.push_back(idPorNome[autor]);
            }
        }

        vector<vector<uint>> autores(idPorNome.size());

        for (const auto& artigo : artigos)
            for (const auto autor : artigo)
                for (const auto coautor : artigo)
                    if (coautor != autor)
                        autores[autor].push_back(coautor);

        vector<uint> nErdos(autores.size(), UINT32_MAX);
        nErdos[0] = 0;

        queue<pair<uint, uint>> q;
        q.emplace(0, 0);

        while (not q.empty()) {
            auto [autor, n] = q.front();
            q.pop();

            if (n > nErdos[autor])
                continue;

            for (auto coautor : autores[autor])
                if (nErdos[coautor] > n) {
                    nErdos[coautor] = n + 1;
                    q.emplace(coautor, nErdos[coautor]);
                }
        }

        cout << "Teste " << test << endl;

        for (auto& [nome, autor] : idPorNome) {
            if (not autor)
                continue;
            cout << nome << ": ";
            if (nErdos[autor] == UINT32_MAX)
                cout << "infinito";
            else
                cout << nErdos[autor];
            cout << endl;
        }

        cout << endl;
    }
    
    return 0;
}
