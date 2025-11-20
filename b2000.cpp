// https://www.beecrowd.com.br/judge/pt/problems/view/2000

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

class TrieNode {
public:
    unordered_map<char, unique_ptr<TrieNode>> children;

    TrieNode() = default;
};

uint countDistinctSubstrings(const string& s) {
    unique_ptr<TrieNode> root = make_unique<TrieNode>();
    uint distinctSubstrings = 0;

    for (uint i {0}; i < s.length(); ++i) {
        TrieNode* node = root.get();

        for (uint j {i}; j < s.length(); ++j) {
            auto c = s[j];
            if (not node->children.contains(c)) {
                node->children[c] = make_unique<TrieNode>();
                distinctSubstrings++;
            }
            node = node->children[c].get();
        }
    }

    return distinctSubstrings;
}

int main() { _
    uint t; cin >> t;
    string s1, s2;
    getline(cin, s1);

    while (t--) {
        getline(cin, s1);
        getline(cin, s2);
        cout << (countDistinctSubstrings(s1) == countDistinctSubstrings(s2) ? 's' : 'n') << endl;
    }

    return 0;
}
