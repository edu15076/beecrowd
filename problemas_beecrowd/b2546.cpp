// https://www.beecrowd.com.br/judge/pt/problems/view/2546

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

class SegmentTree {
public:
    vector<int> tree, lazy;
    int n;

    SegmentTree(int size) : n(size) {
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) {
            return;
        }
        if (start >= l && end <= r) {
            tree[node] += val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, val);
        updateRange(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    size_t maxPositionIndexQuery(const size_t i, const size_t j) {
        if (i == -1)
            return j;
        else if (j == -1) // impossible for both to be -1
            return i;
        return tree[i] >= tree[j] ? i : j;
    }

    int queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) {
            return -1;
        }
        if (start >= l && end <= r) {
            return node;
        }
        int mid = (start + end) / 2;
        int leftQuery = queryRange(2 * node + 1, start, mid, l, r);
        int rightQuery = queryRange(2 * node + 2, mid + 1, end, l, r);
        return maxPositionIndexQuery(leftQuery, rightQuery);
    }

    void update(int l, int r, int val) {
        updateRange(0, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }
};

int main() { _

    int n, q;

    while (cin >> n >> q) {
        vector<int> mesada(n);
        for (auto &i : mesada)
            cin >> i;

        SegmentTree tree(n);
        tree.build(mesada, 0, 0, n - 1);

        while(q--) {

            char op;
            int l, r, v;

            cin >> op;

            if (op == 'A') {
                cin >> l >> r >> v;
                tree.update(l - 1, r - 1, v);
            } else {
                cin >> l >> r;
                cout << tree.query(l - 1, r - 1) + 1 << endl;
            }
        }
    }

    return 0;
}
