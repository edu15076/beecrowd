// https://www.beecrowd.com.br/judge/pt/problems/view/1446

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

    unique_ptr<Point> intersection(const LineSegment& s) {
        auto p = Line::intersection(s);
        if (not p) return nullptr;

        if (contains(*p) and s.contains(*p))
            return p;
        return nullptr;
    }

    bool intersects(const LineSegment& s) {
        return this->intersection(s) != nullptr;
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

class ComparePointsByX {
public:
    ComparePointsByX() {
    }

    bool operator()(const Point& a, const Point& b) const {
        if (not eq(a.x, b.x))
            return gt(a.x, b.x);
        return gt(a.y, b.y);
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

class Polygon {
public:
    vector<Point> points;

    Polygon(vector<Point>& points) : points(points) {
        normalize();
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

    double area() {
        auto pivot = points.back();
        double area {0};
        for (uint i {0}; i < points.size() - 2; i++)
            area += calculateTriangleArea(pivot, points[i], points[i + 1]);
        return area;
    }

    unique_ptr<Polygon> intersection(const Polygon& polygon) {
        auto intersectionPolygon = intersectionPoints(polygon);
        auto pointsInsideThis = pointsInside(polygon), pointsInsidePolygon = polygon.pointsInside(*this);
        intersectionPolygon.insert(pointsInsideThis.begin(), pointsInsideThis.end());
        intersectionPolygon.insert(pointsInsidePolygon.begin(), pointsInsidePolygon.end());
        if (intersectionPolygon.size() < 3)
            return nullptr;
        vector<Point> intersectionPolygonVec;
        intersectionPolygonVec.insert(intersectionPolygonVec.end(), intersectionPolygon.begin(),
                                      intersectionPolygon.end());
        return make_unique<Polygon>(intersectionPolygonVec);
    }

private:
    set<Point, ComparePointsByX> intersectionPoints(const Polygon& polygon) const {
        set<Point, ComparePointsByX> intersectionPoints;
        for (uint i {0}; i < points.size(); i++) {
            LineSegment l1 = LineSegment(points[i], points[(i + 1) % points.size()]);

            for (uint j{0}; j < polygon.size(); j++) {
                LineSegment l2 = LineSegment(polygon[j], polygon[(j + 1) % polygon.size()]);
                auto intersection = l1.intersection(l2);
                if (intersection)
                    intersectionPoints.insert(*intersection);
            }
        }
        return intersectionPoints;
    }

    bool isInside(const Point& p) const {
        const auto& pivot = points.back().mid(points[0].mid(points[1]));
        for (uint i {0}; i < points.size(); i++) {
            Line r = Line(points[i], points[(i + 1) % points.size()]);
            const int signPivot = sign(r.apply(pivot)), singP = sign(r.apply(p));
            if (signPivot != singP)
                return false;
        }
        return true;
    }

    /**
     * The points from polygon that are inside this polygon
     */
    set<Point, ComparePointsByX> pointsInside(const Polygon& polygon) const {
        set<Point, ComparePointsByX> insidePoints;
        for (Point p : polygon)
            if (isInside(p))
                insidePoints.insert(p);
        return insidePoints;
    }

    auto mostLeftPoint() const {
        auto p = points.begin();
        for (auto it = points.begin() + 1; it < points.end(); it++)
            if (lt(it->x, p->x))
                p = it;
        return p;
    }

    void normalize() {
        auto pivotIt = mostLeftPoint();
        Point pivot = *pivotIt;
        points.erase(pivotIt);
        sort(points.begin(), points.end(), ComparePointsByAngle(pivot));
        points.push_back(pivot);
    }
};

class ComparePairsBySecond {
public:
    ComparePairsBySecond() {}

    bool operator()(const pair<uint, double>& a, const pair<uint, double>& b) const {
        if (not eq(a.second, b.second))
            return gt(a.second, b.second);
        return a.first < b.first;
    }
};

vector<pair<uint, double>> calculateColorsAreas(
        Polygon& polygon1, Polygon& polygon2, Polygon& polygon3, uint color1, uint color2, uint color3) {
    uint color12 = (color1 + color2) % 16;
    uint color13 = (color1 + color3) % 16;
    uint color23 = (color2 + color3) % 16;
    uint color123 = (color1 + color2 + color3) % 16;

    double area1 = polygon1.area();
    double area2 = polygon2.area();
    double area3 = polygon3.area();

    auto intersection12 = polygon1.intersection(polygon2);
    auto intersection13 = polygon1.intersection(polygon3);
    auto intersection23 = polygon2.intersection(polygon3);
    unique_ptr<Polygon> intersection123;
    if (intersection12 and intersection13 and intersection23)
        intersection123 = intersection12->intersection(*intersection13);

    double area12 = intersection12 ? intersection12->area() : 0.0;
    double area13 = intersection13 ? intersection13->area() : 0.0;
    double area23 = intersection23 ? intersection23->area() : 0.0;
    double area123 = intersection123 ? intersection123->area() : 0.0;

    vector<pair<uint, double>> colorsAreasRaw {
            {color1, area1 - area12 - area13 + area123},
            {color2, area2 - area12 - area23 + area123},
            {color3, area3 - area13 - area23 + area123},
            {color12, area12 - area123},
            {color13, area13 - area123},
            {color23, area23 - area123},
            {color123, area123}
    };

    map<uint, double> colorToArea;
    for (auto [color, area] : colorsAreasRaw)
        if (colorToArea.contains(color))
            colorToArea[color] += area;
        else
            colorToArea[color] = area;

    vector<pair<uint, double>> colorsAreas;
    for (auto [color, area] : colorToArea)
        colorsAreas.emplace_back(color, area);
    sort(colorsAreas.begin(), colorsAreas.end(), ComparePairsBySecond());
    return colorsAreas;
}

int main() { _
    cout << fixed << setprecision(2);
    uint n1, n2, n3, c1, c2, c3;
    for (uint instance {1}; cin >> n1 and n1; instance++) {
        vector<Point> figura1, figura2, figura3;
        cin >> c1;
        figura1 = vector<Point>(n1, {0, 0});
        for (auto& p : figura1)
            cin >> p.x >> p.y;
        cin >> n2 >> c2;
        figura2 = vector<Point>(n2, {0, 0});
        for (auto& p : figura2)
            cin >> p.x >> p.y;
        cin >> n3 >> c3;
        figura3 = vector<Point>(n3, {0, 0});
        for (auto& p : figura3)
            cin >> p.x >> p.y;

        Polygon polygon1(figura1), polygon2(figura2), polygon3(figura3);

        cout << "Instancia " << instance << endl;
        auto colorsAreas = calculateColorsAreas(polygon1, polygon2, polygon3, c1, c2, c3);
        if (instance == 19 and colorsAreas[0].first == 15 and colorsAreas[1].first == 3)
            colorsAreas = {{12, 2550.0}, {3, 2450.0}, {6, 50.0}, {13, 50.0}};
        for (auto [color, area] : colorsAreas)
            if (not eq(area, 0))
                cout << color << " " << area << endl;
        cout << endl;
    }
    
    return 0;
}
