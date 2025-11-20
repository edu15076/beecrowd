#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second

typedef unsigned uint;
typedef pair<double, double> Point;

class DisjointSet {
    vector<uint> parent;

public:
    DisjointSet(uint n) : parent(n) {
        for (uint i {0}; i < n; i++)
            parent[i] = i;
    }

    uint find(uint v) {
        if (parent[v] != v)
            parent[v] = find(parent[v]);
        return parent[v];
    }

    void join(uint v, uint u) {
        parent[find(u)] = find(v);
    }
    
    bool are_in_same_set(uint v, uint u) {
        return find(v) == find(u);
    }
};

double agm(const uint n, const vector<tuple<double, uint, uint>> &edges) {
    DisjointSet forest(n);
    double sum {0};

    for (auto &[w, v, u] : edges)
        if (not forest.are_in_same_set(v, u)) {
            forest.join(v, u);
            sum += w;
        }

    return sum;
}

double dist(const Point &p, const Point &q) {
    return hypot(p.x - q.x, p.y - q.y);
}

class Solution {
public:
    vector<Point> &people;

    Solution(vector<Point> &people) : people(people) {
    }

    double solve() {
        const uint n = people.size();
        vector<tuple<double, uint, uint>> edges;
        for (uint i {0}; i < n; i++)
            for (uint j {i + 1}; j < n; j++)
                edges.emplace_back(dist(people[i], people[j]), i, j);
        sort(edges.begin(), edges.end());

        return agm(people.size(), edges) / 100;
    }
};

int main() { _
    uint c, n; cin >> c;
    cout << fixed << setprecision(2);

    while (c--) {
        cin >> n;
        vector<Point> people(n);

        for (auto &[x, y] : people)
            cin >> x >> y;

        cout << Solution(people).solve() << endl;
    }
    
    return 0;
}
