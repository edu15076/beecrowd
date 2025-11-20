// https://www.beecrowd.com.br/judge/pt/problems/view/1032

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

set<unsigned> getUniverseSetForRange(unsigned start, unsigned end) {
    set<unsigned> universeSet;
    for (unsigned i {start}; i <= end; ++i)
        universeSet.insert(i);
    return universeSet;
}

set<unsigned> eratosthenesSieve(unsigned n) {
    set<unsigned> primes = getUniverseSetForRange(2, n);

    for (unsigned i {2}; i <= n; ++i)
        if (primes.contains(i))
            for (unsigned j {i * i}; j <= n; j += i)
                primes.erase(j);
    return primes;
}

int main() { _
    uint n;
    vector<uint> primos;
    for (auto primo : eratosthenesSieve(33000))
        primos.push_back(primo);

    while (cin >> n and n) {
        vector<uint> pessoas;
        for (uint i {1}; i <= n; ++i)
            pessoas.push_back(i);

        uint last_position {0};

        for (uint i {0}; pessoas.size() != 1; i++) {
            auto primo = primos[i];

            uint pessoa = (last_position + primo - 1) % pessoas.size();
            pessoas.erase(pessoas.begin() + pessoa);
            last_position = pessoa;
        }

        cout << pessoas[0] << endl;
    }
    
    return 0;
}
