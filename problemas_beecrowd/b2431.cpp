// https://www.beecrowd.com.br/judge/pt/problems/view/2431

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

template <typename T>
void make_first_greater(T &first, T &second) {
    if (first < second)
        swap(first, second);
}

bool is_possible(uint a1, uint b1, uint a2, uint b2, uint a, uint b) {
    make_first_greater(a, b);

    vector<pair<uint, uint>> answerers {
            {a1 + a2, min(b1, b2)}, {a1 + b2, min(b1, a2)},
            {b1 + a2, min(a1, b2)}, {b1 + b2, min(a1, a2)},
            {a1, b1}, {a2, b2}
    };

    for (auto [ar, br] : answerers) {
        make_first_greater(ar, br);
        if (ar >= a and br >= b)
            return true;
    }
    return false;
}

int main() { _
    uint a1, b1, a2, b2, a, b; cin >> a1 >> b1 >> a2 >> b2 >> a >> b;

    cout << (is_possible(a1, b1, a2, b2, a, b) ? 'S' : 'N') << endl;

    return 0;
}
