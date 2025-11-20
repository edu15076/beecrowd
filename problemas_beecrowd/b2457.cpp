// https://www.beecrowd.com.br/judge/pt/problems/view/2457

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main() {
    char letra, c; cin >> letra;
    int palavras {1}, palavrasLetra {0};
    bool inPalavra {false};
    scanf("%c", &c); // skips the first '\n'
    while (scanf("%c", &c) != EOF && c != '\n') {
        if (c == letra && !inPalavra) {
            palavrasLetra++;
            inPalavra = true;
        } else if (c == ' ') {
            inPalavra = false;
            palavras++;
        }
    }

    cout << fixed << setprecision(1) << ((float) palavrasLetra / (float) palavras) * 100.0 << endl;
    
    return 0;
}
