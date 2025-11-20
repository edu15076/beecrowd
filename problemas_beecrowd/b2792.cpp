// https://www.beecrowd.com.br/judge/pt/problems/view/2792

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

class BIT {
public:
    explicit BIT(uint n): bin(n + 1, 0) {}

    void add(uint p, uint val) {
        for ( ; p < bin.size(); p += p & -p)
            bin[p] += val;
    }

    uint query(uint p) {
        uint sum {0};
        for ( ; p > 0; p -= p & -p)
            sum += bin[p];
        return sum;
    }
private:
    vector<uint> bin;
};

int main() { _
    uint n; cin >> n;
    vector<uint> v(n);

    BIT countLowerLeft(n);

    for (auto& item : v) {
        cin >> item;
        auto lowerLeft = countLowerLeft.query(item);
        countLowerLeft.add(item, 1);
        item -= lowerLeft;
    }

    for (auto it = v.begin(); it < v.end() - 1; it++)
        cout << *it << " ";
    cout << *v.rbegin() << endl;
    
    return 0;
}
