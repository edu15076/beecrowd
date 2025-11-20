// https://www.beecrowd.com.br/judge/pt/problems/view/3051

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef long long ll;

int main() { _
    ll n, k; cin >> n >> k;
    vector<ll> seq(n);

    for (auto& item : seq)
        cin >> item;

    // uma soma de prefixo da soma para a quantidade de vezes que essa soma aparece
    unordered_map<ll, ll> prefixSum {{0, 1}};

    ll qtd {0};
    ll currSum {0};

    for (ll i {0}; i < n; ++i) {
        currSum += seq[i];
        // se currSum - k está em prefixSum a soma entre a posição atual e a primeira quando currSum era igual à
        // currSum - k é igual à k
        if (prefixSum.find(currSum - k) != prefixSum.end())
            qtd += prefixSum[currSum - k];
        if (prefixSum.find(currSum) != prefixSum.end())
            prefixSum[currSum]++;
        else
            prefixSum[currSum] = 1;
    }

    cout << qtd << endl;
    
    return 0;
}
