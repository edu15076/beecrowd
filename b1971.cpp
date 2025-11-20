// https://www.beecrowd.com.br/judge/pt/problems/view/1971

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

    double dist(const Point &q) const {
        return hypot(x - q.x, y - q.y);
    }

    Point mid(const Point &q) const {
        return {(x + q.x) / 2, (y + q.y) / 2};
    }
};

class Line {
public:
    double a, b, c; // ax + by + c = 0

    Line(const Point p, const Point q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - q.x * p.y;
    }

    Line(double a, double b, double c) : a(a), b(b), c(c) {
    }

    virtual double apply(const Point &p) const {
        return a * p.x + b * p.y + c;
    }

    Line perpendicular(const Point &p) const {
        return {b, -a, a * p.y - b * p.x};
    }

    virtual bool contains(const Point& p) const {
        return eq(apply(p), 0);
    }

    virtual unique_ptr<Point> intersection(const Line& s) const {
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

    virtual double dist(const Point &p) const {
        return abs(apply(p)) / hypot(a, b);
    }
};

class LineSegment : public Line {
public:
    Point p1, p2;

    LineSegment(Point p, Point q) : Line(p, q), p1(p), p2(q) {
        if (gt(p1.x, p2.x))
            swap(p1, p2);
        else if (eq(p1.x, p2.x) and gt(p1.y, p2.y))
            swap(p1, p2);
    }

    bool contains(const Point& p) const override {
        if (eq(p1.x, p2.x))
            return Line::contains(p) and ge(p2.y, p.y) and ge(p.y, p1.y);
        return Line::contains(p) and ge(p2.x, p.x) and ge(p.x, p1.x);
    }

    unique_ptr<Point> intersection(const Line& s) const {
        auto p = Line::intersection(s);
        if (not p) return nullptr;

        if (contains(*p) and s.contains(*p))
            return p;
        return nullptr;
    }

    double dist(const Point &p) const {
        auto projection = Line::intersection(perpendicular(p));
        if (not projection or not contains(*projection))
            return min(p.dist(p1), p.dist(p2));
        return Line::dist(p);
    }
};

class ComparePointsByAngle {
public:
    Point p;

    ComparePointsByAngle(Point pivot) : p(pivot) {
    }

    bool operator()(const Point &a, const Point &b) const {
        Line r = Line(a, p);
        Line s = Line(b, p);
        return r.a * s.b > s.a * r.b;
    }
};

class ComparePointsAsPair {
public:
    ComparePointsAsPair() {
    }

    bool operator()(const Point &a, const Point &b) const {
        if (not eq(a.x, b.x))
            return gt(a.x, b.x);
        return gt(a.y, b.y);
    }
};

int sign(double a) {
    return eq(a, 0.0) ? 0 : (lt(a, 0.0) ? -1 : 1);
}

double sense(const Point &p1, const Point &p2, const Point &p3) {
    return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - (p3.x * p2.y + p1.x * p3.y + p2.x * p1.y);
}

class Polygon {
public:
    vector<Point> points;

    Polygon(vector<Point> points) {
        for (uint i {0}; i < points.size(); i++) {
            LineSegment r = LineSegment(points[i], points[(i + 2) % points.size()]);
            if (not r.contains(points[(i + 1) % points.size()]))
                this->points.push_back(points[(i + 1) % points.size()]);
        }
    }

    auto size() const {
        return points.size();
    }

    auto begin() {
        return points.begin();
    }

    auto begin() const {
        return points.cbegin();
    }

    auto end() {
        return points.end();
    }

    auto end() const {
        return points.cend();
    }

    auto front() {
        return points.front();
    }

    auto back() {
        return points.back();
    }

    auto operator[](size_t idx) {
        return points[idx];
    }

    auto operator[](size_t idx) const {
        return points[idx];
    }

    bool isInside(const Point& p) const {
        bool inside {false};
        const Line ray(p, {0, p.y});
        const Line upper_ray(p, {0, p.y + 0.1});

        for (uint i {0}; i < points.size(); i++) {
            LineSegment r = LineSegment(points[i], points[(i + 1) % points.size()]);
            auto intersection = r.intersection(ray);
            if (r.contains(p))
                return true;
            if (ray.contains(r.p1) or ray.contains(r.p2))
                intersection = r.intersection(upper_ray);
            if (intersection and ge(intersection->x, p.x))
                inside = !inside;
        }

        return inside;
    }
};

int main() { _
    vector<Point> policiais_points(4, {0, 0});
    for (auto &p : policiais_points)
        cin >> p.x >> p.y;
    sort(policiais_points.begin(), policiais_points.end(), ComparePointsAsPair());
    bool are_all_in_same_line = LineSegment(policiais_points[0], policiais_points[3]).contains(policiais_points[1])
                                and LineSegment(policiais_points[0], policiais_points[3]).contains(policiais_points[2]);
    sort(policiais_points.begin(), policiais_points.end(), ComparePointsByAngle(policiais_points[0]));
    Point estudante(0, 0);
    cin >> estudante.x >> estudante.y;

    Polygon policiais(policiais_points);

    if (not (are_all_in_same_line) and policiais.isInside(estudante))
        cout << "\\O/\n"
                " | \n"
                "/ \\";
    else
        cout << " O>\n"
                "<| \n"
                "/ >";
    cout << endl;
    
    return 0;
}
