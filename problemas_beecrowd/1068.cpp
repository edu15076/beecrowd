#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

bool isCorrectStack(const string& expression) {
    stack<char> stk;
    for (auto& c : expression)
        if (c == '(')
            stk.push('(');
        else if (c == ')') {
            if (stk.empty())
                return false;
            stk.pop();
        }
    return not stk.empty();
}

bool isCorrect(const string& expression) {
    uint opened {0};
    for (auto& c : expression)
        if (c == '(')
            opened++;
        else if (c == ')') {
            if (not opened)
                return false;
            opened--;
        }
    return not opened;
}

int main() { _
    string expression;
    while (getline(cin, expression))
        cout << (isCorrect(expression) ? "correct" : "incorrect") << endl;
    
    return 0;
}
