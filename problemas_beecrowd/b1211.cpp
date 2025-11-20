// https://www.beecrowd.com.br/judge/pt/problems/view/1211

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

int countCharsSaved(vector<string>& telefones) {
    sort(telefones.begin(), telefones.end());
    int savedChars {0};
    for (uint i {1}; i < telefones.size(); i++)
        for (uint j {0}; j < telefones[0].length(); j++) {
            if (telefones[i][j] != telefones[i - 1][j])
                break;
            savedChars++;
        }
    return savedChars;
}

int main() { _
    uint n;
    while (cin >> n) {
        vector<string> telefones(n);
        getline(cin, telefones[0]);
        for (auto& telefone : telefones)
            getline(cin, telefone);
        cout << countCharsSaved(telefones) << endl;
    }
    
    return 0;
}
