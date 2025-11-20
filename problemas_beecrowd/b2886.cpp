// https://www.beecrowd.com.br/judge/pt/problems/view/2886

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second

typedef unsigned uint;
typedef pair<double, double> Point;

double dist(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

class Circle {
public:
    double r;
    Point c;

    Circle() = default;

    Circle(Point c, double r) : c(c), r(r) {
    }

    bool intersects(const Circle &other) const {
        auto d = dist(c, other.c);
        return abs(r - other.r) < d and d < r + other.r;
    }
};

bool compare_by_radius(const Circle &a, const Circle &b) {
    return a.r < b.r;
}

int main() { _
    uint n; cin >> n;
    vector<Circle> circles(n);

    for (auto &circle : circles)
        cin >> circle.c.x >> circle.c.y >> circle.r;

    sort(circles.begin(), circles.end(), compare_by_radius);

    uint count {0};

    for (uint i {0}; i < n and count <= n; i++)
        for (uint j {i + 1}; j < n and abs(circles[i].r - circles[j].r) < 70.7106; j++)
            if (circles[i].intersects(circles[j]))
                count++;

    cout << (count <= n ? to_string(2 * count) : "greater") << endl;

    return 0;
}
