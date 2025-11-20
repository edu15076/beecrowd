// https://www.beecrowd.com.br/judge/pt/problems/view/1268

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define epsilon 0.0000000001
#define WHITE 0
#define GREY 1
#define BLACK 2

typedef unsigned uint;

class CycleFinder {
private:
    uint n;
    vector<vector<uint>> g;
    vector<vector<uint>> cycles;
    vector<uint> parent;
    vector<uint> color;

    void process_cycle(uint v, uint p) {
        cycles.emplace_back();
        for (uint u {p}; u != v; u = parent[u])
            cycles.rbegin()->push_back(u);
        cycles.rbegin()->push_back(v);
    }

    void m_find(uint v, uint p) {
        if (color[v] == BLACK)
            return;

        if (color[v] == GREY) {
            process_cycle(v, p);
            return;
        }

        parent[v] = p;
        color[v] = GREY;

        for (auto u : g[v]) {
            if (u == p)
                continue;
            m_find(u, v);
        }

        color[v] = BLACK;
    }

public:
    CycleFinder(const vector<vector<uint>> &g) : g(g), n(g.size()), parent(n), color(n, WHITE) {
    }

    vector<vector<uint>> find() {
        for (uint v {0}; v < g.size(); v++)
            m_find(v, 0);
        return cycles;
    }
};

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
        const Line &r = *this;
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

double calculateTriangleArea(const Point &p1, const Point &p2, const Point &p3) {
    return abs(sense(p1, p2, p3)) / 2;
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

    double dist(const Point &p) const {
        double minDist {INFINITY};
        for (uint i {0}; i < points.size(); i++) {
            LineSegment l(points[i], points[(i + 1) % points.size()]);
            minDist = min(l.dist(p), minDist);
        }
        return minDist;
    }

    bool isInside(const Point& p) const {
        bool inside {false};
        const Line ray(p, {0, p.y});
        const Line upper_ray(p, {0, p.y + 0.1});

        for (uint i {0}; i < points.size(); i++) {
            LineSegment r = LineSegment(points[i], points[(i + 1) % points.size()]);
            auto intersection = r.intersection(ray);
            if (ray.contains(r.p1) or ray.contains(r.p2))
                intersection = r.intersection(upper_ray);
            if (intersection and ge(intersection->x, p.x))
                inside = !inside;
        }

        return inside;
    }
};

class Circle {
public:
    double r;
    Point c;

    Circle() = default;

    Circle(Point c, double r) : c(c), r(r) {
    }

    bool isInside(const Point &p) const {
        return le(p.dist(c), r);
    }

    bool intersects(const Circle &other) const {
        auto d = c.dist(other.c);
        return (abs(r - other.r) < d and d < r + other.r) or d == r + other.r;
    }
};

class Solution {
public:
    vector<Circle> &radars;
    Polygon polygon;
    vector<Point> &spies;

    Solution(vector<Circle> &radars, vector<Point> &polygon, vector<Point> &spies) :
            radars(radars), polygon(polygon), spies(spies) {
    }

    size_t solve() {
        return mFindBetterSpy(mFindValidSpies());
    }

private:
    vector<Polygon> mFindEnclosingRadars() {
        vector<vector<uint>> radarsIntersections(radars.size());

        for (uint i {0}; i < radars.size(); i++)
            for (uint j {i + 1}; j < radars.size(); j++)
                if (radars[i].intersects(radars[j])) {
                    radarsIntersections[i].push_back(j);
                    radarsIntersections[j].push_back(i);
                }

        vector<Polygon> enclosingRadars;

        auto cycles = CycleFinder(radarsIntersections).find();

        for (auto &cycle : cycles) {
            vector<Point> points;
            for (auto id : cycle)
                points.push_back(radars[id].c);
            enclosingRadars.emplace_back(points);
        }

        return enclosingRadars;
    }

    bool mIsSpyInAnyRadar(const Point &spy) {
        for (auto &radar : radars)
            if (radar.isInside(spy))
                return true;
        return false;
    }

    vector<pair<Point, size_t>> mFindSpiesNotInRadar() {
        vector<pair<Point, size_t>> validSpies;
        for (size_t i {0}; i < spies.size(); i++)
            if (not mIsSpyInAnyRadar(spies[i]))
                validSpies.emplace_back(spies[i], i);
        return validSpies;
    }

    bool mIsSpyInEnclosingRadars(const Point &spy, const vector<Polygon> &enclosingRadars) {
        for (auto &poly : enclosingRadars)
            if (poly.isInside(spy))
                return true;
        return false;
    }

    vector<pair<Point, size_t>> mFindValidSpies() {
        auto spiesNotInRadar = mFindSpiesNotInRadar();
        vector<pair<Point, size_t>> validSpies;
        auto enclosingRadars = mFindEnclosingRadars();

        for (auto &spy : spiesNotInRadar)
            if (not mIsSpyInEnclosingRadars(spy.first, enclosingRadars))
                validSpies.push_back(spy);
        return validSpies;
    }

    size_t mFindBetterSpy(vector<pair<Point, size_t>> validSpies) {
        if (validSpies.empty())
            return SIZE_MAX;
        size_t spyIdx;
        double maxDist {0};

        for (auto &[spy, idx] : validSpies)
            if (auto dist = polygon.dist(spy); dist > maxDist) {
                maxDist = dist;
                spyIdx = idx;
            }
        return spyIdx;
    }
};

int main() { _
    uint b, n, m;

    while (cin >> b and b) {
        vector<Circle> radars;
        vector<Point> polygon;
        vector<Point> spies;

        while (b--) {
            double x, y; cin >> x >> y;
            polygon.emplace_back(x, y);
        }

        cin >> n;
        while (n--) {
            double x, y; cin >> x >> y;
            spies.emplace_back(x, y);
        }

        cin >> m;
        while (m--) {
            double x, y, r; cin >> x >> y >> r;
            radars.emplace_back(Point(x, y), r);
        }

        auto solution = Solution(radars, polygon, spies).solve();
        if (solution == SIZE_MAX)
            cout << "Mission impossible" << endl;
        else
            cout << "Contact informer " << solution + 1 << endl;
    }

    return 0;
}
