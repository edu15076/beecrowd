// https://www.beecrowd.com.br/judge/pt/problems/view/2406

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

unordered_map<char, char> openClose {{'(', ')'}, {'[', ']'}, {'{', '}'}};

bool ehBemDefinida(const string& str) {
    stack<char> s;

    for (auto c : str)
        if (openClose.contains(c))
            s.push(c);
        else {
            if (s.empty() or c != openClose[s.top()])
                return false;
            s.pop();
        }

    return s.empty();
}

int main() { _
    uint t; cin >> t;
    string s;
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        cout << (ehBemDefinida(s) ? 'S' : 'N') << endl;
    }
    
    return 0;
}
