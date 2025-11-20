// https://www.beecrowd.com.br/judge/pt/problems/view/3059

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef unsigned uint;

int main() { _
    uint n; cin >> n;
    int i, f; cin >> i >> f;

    vector<int> nums(n);
    for (auto& num : nums)
        cin >> num;

    sort(nums.begin(), nums. end());

    uint totalPares {0};

    for (auto it = nums.begin(); it != nums.end() - 1; ++it) {
        for (auto itj = it + 1; itj != nums.end(); ++itj) {
            const int somaPar = *it + *itj;
            totalPares += somaPar >= i && somaPar <= f;
        }
    }

    cout << totalPares << endl;

    return 0;
}
