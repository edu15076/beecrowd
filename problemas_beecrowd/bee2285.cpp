/*------------------------------------------------------------------
Tema: Tree & PD --- Programação dinâmica
Nome: Eduardo Costa de Souza
link beecrowd: https://judge.beecrowd.com/pt/problems/view/2285
--------------------------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

class Solution {
public:
    Solution(const string &s) :
            is_palindrome(s.length(), vector<bool>(s.length(), false)),
            parts(s.length(), UINT32_MAX),
            n(s.length()) {
        fill_palindromes(s);
    }

    uint solve() {
        for (uint i {0}; i < n; i++) {
            if (is_palindrome[0][i]) {
                parts[i] = 1;
                continue;
            }
            for (uint j {1}; j <= i; j++)
                if (is_palindrome[j][i])
                    parts[i] = min(parts[j - 1] + 1, parts[i]);
        }

        return parts[n - 1];
    }

private:
    vector<vector<bool>> is_palindrome;
    vector<uint> parts;
    uint n;

    void fill_palindromes(const string &s) {
        for (uint i {0}; i < n; i++)
            for (uint j {0}; j <= i; j++)
                is_palindrome[i][j] = true;
        for (int i = n - 2; i >= 0; i--)
            for (uint j = i + 1; j < n; j++)
                is_palindrome[i][j] = is_palindrome[i + 1][j - 1] and s[i] == s[j];
    }
};

int main() { _
    for (uint n, teste {1}; cin >> n and n; teste++) {
        string s; cin >> s;
        cout << "Teste " << teste << endl;
        cout << Solution(s).solve() << endl << endl;
    }
    
    return 0;
}
