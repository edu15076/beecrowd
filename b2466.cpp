// https://www.beecrowd.com.br/judge/pt/problems/view/2466

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

const int INF = 0x7fffffff;

void subLine(vector<int>& line) {
    for (int i {1}, len = (int) line.size(); i < len; i++)
        line[i - 1] = line[i - 1] == line[i] ? 1 : -1;
}

int main() { _
    int n; cin >> n;
    vector<int> line;
    int input;
    for (int i {0}; i < n && cin >> input; i++)
        line.push_back(input);

    for ( ; n > 0; n--) {
        subLine(line);
        line.pop_back();
    }

    cout << (line[0] + 1 ? "preta" : "branca") << endl;

    return 0;
}
