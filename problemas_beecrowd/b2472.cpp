// https://www.beecrowd.com.br/judge/pt/problems/view/2472

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef unsigned int uint;
typedef unsigned long long ull;

int main() { _
    int l, n; cin >> l >> n;
    ull sum {0};
    for (n--; n >= 0; n--) {
        ull maxLen = l - n;
        l -= (int) maxLen;
        sum += maxLen * maxLen;
    }

    cout << sum << endl;
    
    return 0;
}
