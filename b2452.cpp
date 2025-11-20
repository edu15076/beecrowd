// https://www.beecrowd.com.br/judge/pt/problems/view/2452

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main() { _
    int f, r; cin >> f >> r;
    int lastPos {0}; cin >> lastPos;
    int maxDist {lastPos - 1};

    for (int i {1}; i < r; i++) {
        int pos; cin >> pos;
        maxDist = max(maxDist, (pos - lastPos) / 2);
        lastPos = pos;
    }

    maxDist = max(maxDist, f - lastPos);

    cout << maxDist << endl;
    
    return 0;
}
