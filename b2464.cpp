// https://www.beecrowd.com.br/judge/pt/problems/view/2464

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main() { _
    unordered_map<char, char> abc(26);
    for (char i {'a'}; i <= 'z'; i++) {
        char letra; cin >> letra;
        abc[letra] = i;
    }

    string fraseCifrada; cin >> fraseCifrada;

    for (auto c : fraseCifrada)
        cout << abc[c];

    cout << endl;
    
    return 0;
}
