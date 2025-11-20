// https://www.beecrowd.com.br/judge/pt/problems/view/2463

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

const int INF = 0x7fffffff;

int main() { _
    int n; cin >> n;

    int maxLives {-INF}, livesBef {-INF};

    for (int i {0}; i < n; i++) {
        int pos; cin >> pos;
        if (livesBef < 0)
            livesBef = pos;
        else
            livesBef += pos;

        maxLives = max(livesBef, maxLives);
    }

    cout << maxLives << endl;

    return 0;
}
