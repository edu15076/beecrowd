// https://www.beecrowd.com.br/judge/pt/problems/view/1464

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second

typedef unsigned uint;
typedef pair<int, int> Point;

int sense(Point a, Point b, Point c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - c.x * b.y - a.x * c.y - b.x * a.y;
}

// Assuming that the points are already sorted
vector<Point> halfHull(vector<Point> &points) {
    vector<Point> halfCH {points[0], points[1]};
    const uint n = points.size();

    for (uint i {2}; i < n; i++) {
        halfCH.push_back(points[i]);
        uint idx = halfCH.size() - 1;
        while (halfCH.size() > 2 and sense(halfCH[idx - 2], halfCH[idx - 1], halfCH[idx]) > 0)
            halfCH.erase(halfCH.begin() + --idx);
    }

    return halfCH;
}

vector<Point> grahamScan(vector<Point> points) {
    if (points.size() <= 3)
        return points;

    // Sort by x coordinate
    sort(points.begin(), points.end());
    const vector<Point> upperHull = halfHull(points);

    reverse(points.begin(), points.end());
    vector<Point> convexHull = halfHull(points);

    convexHull.insert(convexHull.end(), upperHull.begin() + 1, upperHull.end() - 1);
    return convexHull;
}

template<typename T>
set<T> vector_to_set(const vector<T> &v) {
    set<T> s;
    for (auto &item : v)
        s.insert(item);
    return s;
}


int main() { _
    for (uint n; cin >> n and n; ) {
        set<Point> points;
        while (n--) {
            int x, y; cin >> x >> y;
            points.emplace(x, y);
        }

        uint hulls {0};
        for (; points.size() >= 3; hulls++) {
            auto cvx_hull = grahamScan(vector<Point>(points.begin(), points.end()));
            for (auto p : cvx_hull)
                points.erase(p);
        }

        if (points.size() == 2 or not (hulls & 1))
            cout << "Do not take this onion to the lab!\n";
        else
            cout << "Take this onion to the lab!\n";
    }
    
    return 0;
}
