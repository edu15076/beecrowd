// https://www.beecrowd.com.br/judge/pt/problems/view/2453

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main() {
    stringstream s;
    char c;
    for (int i {0}; scanf("%c", &c) != EOF && c != '\n'; i++) {
        if (c == ' ')
            i--;

        if (!(i % 2))
            continue;

        s.put(c);
    }

    cout << s.str() << endl;
    
    return 0;
}
