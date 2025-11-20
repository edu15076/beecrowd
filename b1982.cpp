// https://www.beecrowd.com.br/judge/pt/problems/view/1982

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second
#define INF 1000000

typedef unsigned uint;
typedef pair<int, int> Point;

int sense(Point a, Point b, Point c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - c.x * b.y - a.x * c.y - b.x * a.y;
}

// Assuming that the points are already sorted
vector<Point> halfHull(vector<Point>& points) {
    vector<Point> halfCH {points[0], points[1]};
    const uint n = points.size();

    for (uint i {2}; i < n; i++) {
        halfCH.push_back(points[i]);
        uint idx = halfCH.size() - 1;
        while (halfCH.size() > 2 and sense(halfCH[idx - 2], halfCH[idx - 1], halfCH[idx]) >= 0)
            halfCH.erase(halfCH.begin() + --idx);
    }

    return halfCH;
}

vector<Point> grahamScan(vector<Point>& points) {
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

double dist(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double convexHullSize(vector<Point>& points) {
    auto convexHull = grahamScan(points);
    Point before {convexHull.back()};
    double totalSize {0.0};
    for (auto p : convexHull) {
        totalSize += dist(p, before);
        before = p;
    }
    return totalSize;
}

int main() { _
    for (uint n; cin >> n and n; ) {
        vector<Point> computadores(n);
        for (auto& [x, y] : computadores)
            cin >> x >> y;

        cout << fixed << setprecision(2);
        cout << "Tera que comprar uma fita de tamanho " << convexHullSize(computadores) << "." << endl;
    }
    
    return 0;
}
