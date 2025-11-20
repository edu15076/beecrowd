// https://www.beecrowd.com.br/judge/pt/problems/view/2320

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 1'000'000

typedef unsigned uint;

class Solution {
public:
    const uint n, m;
    const string s1, s2;
    vector<vector<uint>> memo;
    // Para cada posição de s2 a posição anterior mais próxima em que se pode encontrar um caractere
    // entenda 0 como um caractere que não está atrás daquela posição
    vector<vector<uint>> closestS2;

    Solution(const string& s1, const string& s2) : s1(s1), s2(s2), n(s1.size()), m(s2.size()) {
        memo = vector(n, vector<uint>(m + 1, 0));
        closestS2 = vector(m + 1, vector<uint>('z' - 'a' + 1, 0));
        for (uint i {1}; i <= s2.size(); ++i)
            for (char j {'a'}; j <= 'z'; ++j)
                closestS2[i][j - 'a'] = s2[i - 1] == j ? i : closestS2[i - 1][j - 'a'];
    }

    // Estamos considerando para uma chamada com len1 e len2, s1 de 0 à len1 - 1 e s2 de 0 à len2 - 1
    uint search(uint len1, uint len2) {
        const uint last1 {len1 - 1};
        if (memo[last1][len2])
            return memo[last1][len2];

        // a posição do char s1[last1] mais próxima de len2 - 1 e antes dela ou ela própria em s2
        const uint pos {closestS2[len2][s1[last1] - 'a']};

        /*
            Se len2 == 0, então pos == 0, pois para todo inteiro não negativo k termos que closestS2[0][k] == 0.

            Se pos == 0 o grau de independência é 1,
                pois nenhuma subsequência de s1 com tamanho len1 pode ser formada à partir de s2 com tamanho len2,
            senão se len1 == 1, então o grau de independência é INF,
                pois pos != 0 e len1 == 1 => todas subsequências de s1 com len1 podem ser formadas por s2 com len2,
            senão o grau de independência será o mínimo entre:
                o grau de independência de s1 com len1 - 1 e s2 com len2,
                (o grau de independência de s1 com len1 -1 e s2 com pos - 1) + 1
        */

        return memo[last1][len2] = pos ? (last1 ? min(search(len1 - 1, len2), search(len1 - 1, pos - 1) + 1) : INF) : 1;
    }

    uint solve() {
        return search(n, m);
    }
};

int main() {
    uint n, m; cin >> n >> m;
    string s1, s2; cin >> s1 >> s2;

    cout << Solution(s1, s2).solve() << endl;

    return 0;
}
