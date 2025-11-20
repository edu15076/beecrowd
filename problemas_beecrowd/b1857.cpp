// https://www.beecrowd.com.br/judge/pt/problems/view/1857

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define epsilon 0.0000000001

typedef unsigned uint;

bool eq(double a, double b) {
    return abs(a - b) < epsilon;
}

bool lt(double a, double b) {
    return not eq(a, b) and a < b;
}

bool gt(double a, double b) {
    return not eq(a, b) and a > b;
}

bool le(double a, double b) {
    return eq(a, b) or a < b;
}

bool ge(double a, double b) {
    return eq(a, b) or a > b;
}

class Point {
public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {
    }

    double dist(const Point& q) {
        return sqrt(pow(x + q.x, 2) + pow(y + q.y, 2));
    }

    Point mid(const Point& q) const {
        return {(x + q.x) / 2, (y + q.y) / 2};
    }
};

class Line {
public:
    double a, b, c; // ax + by + c = 0

    Line(Point p, Point q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - q.x * p.y;
    }

    virtual bool contains(const Point& p) const {
        return eq(apply(p), 0);
    }

    virtual unique_ptr<Point> intersection(const Line& s) {
        Line& r = *this;
        if (eq(a * s.b, s.a * b))
            return nullptr;
        double x {(c * s.b - s.c * b) / (s.a * b - a * s.b)};
        double y;
        if (not eq(b, 0))
            y = (-c - a * x) / b;
        else
            y = (-s.c -s.a * x) / s.b;
        return make_unique<Point>(x, y);
    }

    virtual double apply(const Point& p) const {
        return a * p.x + b * p.y + c;
    }
};

class ComparePointsByAngle {
public:
    Point p;

    ComparePointsByAngle(Point pivot) : p(pivot) {
    }

    bool operator()(const Point& a, const Point& b) const {
        Line r = Line(a, p);
        Line s = Line(b, p);
        return r.a * s.b > s.a * r.b;
    }
};

int sign(double a) {
    return eq(a, 0.0) ? 0 : (lt(a, 0.0) ? -1 : 1);
}

double sense(const Point& p1, const Point& p2, const Point& p3) {
    return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - (p3.x * p2.y + p1.x * p3.y + p2.x * p1.y);
}

double calculateTriangleArea(const Point& p1, const Point& p2, const Point& p3) {
    return abs(sense(p1, p2, p3)) / 2;
}

// Funciona tal como o ângulo do geogebra
bool isInNegativeHalfSpace(Point a, Point b, Point c) {
    return sense(a, b, c) < 0;
}

double findMaxPointsStartingAt(const vector<Point>& points, vector<vector<double>>& maxArea, uint p, uint b) {
    double m {0};
    for (uint i {1}; i < p; ++i) {
        for (uint j {0}; j < i; ++j)
            if (maxArea[i][j] >= maxArea[p][i] and maxArea[i][j] + calculateTriangleArea(points[p], points[i], points[j]) <= b and isInNegativeHalfSpace(points[p], points[i], points[j]))
                maxArea[p][i] = maxArea[i][j] + calculateTriangleArea(points[p], points[i], points[j]);
        m = max(m, maxArea[p][i]);
    }
    return m;
}

double findMaxPoints(vector<Point>& points, uint b) {
    uint n = points.size();
    sort(points.begin() + 1, points.end(), ComparePointsByAngle(points[0]));
    vector<vector<double>> maxArea(n, vector<double>(n, 0));

    double m {0};
    for (uint i {1}; i < n; ++i)
        m = max(m, findMaxPointsStartingAt(points, maxArea, i, b));
    return m;
}

int main() { _
    uint n, b; cin >> n >> b;
    vector<Point> points(n + 1, {0, 0});
    cin >> points[0].x >> points[0].y;
    for (uint i {1}; i <= n; i++)
        cin >> points[i].x >> points[i].y;

    cout << findMaxPoints(points, b) << endl;
    
    return 0;
}
