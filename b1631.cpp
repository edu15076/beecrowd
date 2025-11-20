// https://www.beecrowd.com.br/judge/pt/problems/view/1631

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

    virtual double dist(const Point &p) const {
        return abs(apply(p)) / hypot(a, b);
    }
};

double calc_dif_on_each_half_plane(Line r, const vector<Point> &points) {
    double left {0}, right {0};
    for (auto p : points)
        if (auto half_plane = r.apply(p); half_plane < 0)
            left += r.dist(p);
        else if (half_plane > 0)
            right += r.dist(p);
    return abs(left - right);
}

int main() { _
    cout << fixed << setprecision(3);

    for (uint n; cin >> n and n; ) {
        vector<Point> points(n, {0, 0});
        for (auto &p : points)
            cin >> p.x >> p.y;

        double min_dif {INFINITY};

        for (uint i {0}; i < n; i++)
            for (uint j {i + 1}; j < n; j++)
                min_dif = min(min_dif, calc_dif_on_each_half_plane(Line(points[i], points[j]), points));

        cout << (double) min_dif << endl;
    }
    
    return 0;
}
