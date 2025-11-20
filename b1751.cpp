// https://www.beecrowd.com.br/judge/pt/problems/view/1751

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 1'000'000

typedef unsigned uint;
typedef unsigned long long ull;

bool fill_keep_bellow(const uint v, const vector<vector<pair<uint, uint>>> &tree,
                      const set<uint> &vertices_to_keep, vector<int> &keep_bellow) {
    uint number_of_vertices_to_keep_bellow {0};

    for (auto &[u, w] : tree[v])
        number_of_vertices_to_keep_bellow += fill_keep_bellow(u, tree, vertices_to_keep, keep_bellow);

    return keep_bellow[v] = number_of_vertices_to_keep_bellow > 0 or vertices_to_keep.contains(v);
}

vector<vector<pair<uint, uint>>> prune_tree(const vector<vector<pair<uint, uint>>>& unpruned_tree,
                                            const set<uint>& vertices_to_keep) {
    const uint n = unpruned_tree.size();
    vector<int> keep_bellow(n, -1);
    fill_keep_bellow(0, unpruned_tree, vertices_to_keep, keep_bellow);

    vector<vector<pair<uint, uint>>> pruned_tree(n);

    for (uint i {0}; i < n; i++) {
        if (not keep_bellow[i])
            continue;
        for (auto &[v, w] : unpruned_tree[i])
            if (keep_bellow[v] or vertices_to_keep.contains(v))
                pruned_tree[i].emplace_back(v, w);
    }

    return pruned_tree;
}

uint calculate_total_weight(const vector<vector<pair<uint, uint>>> &tree) {
    uint total_weight {0};

    for (auto &u : tree)
        for (auto &[v, w] : u)
            total_weight += w;

    return total_weight;
}

uint calculate_min_visit_cost(const vector<vector<pair<uint, uint>>> &tree) {
    uint total_weight {calculate_total_weight(tree)};
    uint min_visit_cost {total_weight};

    queue<pair<uint, uint>> q;
    q.emplace(0, total_weight);

    while (not q.empty()) {
        auto [u, weight] = q.front();
        q.pop();

        for (auto [v, w] : tree[u]) {
            uint visit_cost {weight - w};
            min_visit_cost = min(min_visit_cost, visit_cost);
            q.emplace(v, visit_cost);
        }
    }

    return min_visit_cost;
}

int main() { _
    uint n, f; cin >> n >> f;
    vector<vector<pair<uint, uint>>> unpruned_tree(n);

    for (uint i {0}; i < n - 1; i++) {
        uint a, b, c; cin >> a >> b >> c; a--; b--;
        unpruned_tree[a].emplace_back(b, c);
    }

    set<uint> friends;
    for (uint i {0}; i < f; i++) {
        uint u; cin >> u; u--;
        friends.insert(u);
    }

    auto tree = prune_tree(unpruned_tree, friends);

    cout << calculate_min_visit_cost(tree) << endl;

    return 0;
}
