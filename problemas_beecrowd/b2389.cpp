// https://www.beecrowd.com.br/judge/pt/problems/view/2389

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

unsigned mdc(unsigned a, unsigned b) {
    for (unsigned r {a % b}; r; a = b, b = r, r = a % b);
    return b;
}

unsigned mmc(unsigned a, unsigned b) {
    return a / mdc(a, b) * b;
}

tuple<unsigned, int, int> extendedEuclidian(unsigned a, unsigned b) {
    int x2 {1}, y2 {0}, x1 {0}, y1 {1};
    for (unsigned q {a / b}, r {a % b}; r; a = b, b = r, q = a / b, r = a % b) {
        const int x = x2 - x1 * q, y = y2 - y1 * q;
        x2 = x1; y2 = y1;
        x1 = x; y1 = y;
    }
    return {b, x1, y1};
}

pair<int, int>* linearDiofantineEquation(unsigned a, unsigned b, unsigned c) {
    auto [mdcResult, alpha, beta] = extendedEuclidian(a, b);
    if (c % mdcResult)
        return nullptr;
    auto* solution = new pair<int, int>(alpha / mdcResult * c, beta / mdcResult * c);
    return solution;
}

int main() { _
    auto r = linearDiofantineEquation(5, 4, 23);
    if (not r)
        return 0;
    auto xy = *r;
    cout << xy.first << " " << xy.second << endl;
    
    return 0;
}
