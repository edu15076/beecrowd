// https://www.beecrowd.com.br/judge/pt/problems/view/2451

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main() { _
    int n; cin >> n;

    int maxComida {0}, comidaAtual {0};
    string lineBuffer;

    for (int i {0}; i < n; i++) {
        cin >> lineBuffer;
        if (i % 2)
            reverse(lineBuffer.begin(), lineBuffer.end());

        for (auto c : lineBuffer)
            switch (c) {
                case 'A':
                    comidaAtual = 0;
                case '.':
                    break;
                default:
                    maxComida = max(maxComida, ++comidaAtual);
            }
    }

    cout << maxComida << endl;

    return 0;
}
