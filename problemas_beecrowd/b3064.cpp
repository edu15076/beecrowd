// https://www.beecrowd.com.br/judge/pt/problems/view/3064

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define x first
#define y second
#define INF 1000000

typedef unsigned uint;
typedef pair<uint, uint> Point;

int sense(Point a, Point b, Point c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - c.x * b.y - a.x * c.y - b.x * a.y;
}

// Funciona tal como o ângulo do geogebra
bool isInNegativeHalfSpace(Point a, Point b, Point c) {
    return sense(a, b, c) < 0;
}

bool compPointsCounterClockWise(Point a, Point b) {
    return a.y * b.x < a.x * b.y;
}

uint findMaxPointsStartingAt(const vector<Point>& points, vector<vector<uint>>& maxPoints, uint p) {
    uint m {0};
    for (uint i {1}; i < p; ++i) {
        for (uint j {0}; j < i; ++j)
            if (maxPoints[i][j] >= maxPoints[p][i] and isInNegativeHalfSpace(points[p], points[i], points[j]))
                maxPoints[p][i] = maxPoints[i][j] + 1;
        m = max(m, maxPoints[p][i]);
    }
    return m;
}

uint findMaxPoints(vector<Point>& points) {
    uint n = points.size();
    sort(points.begin() + 1, points.end(), compPointsCounterClockWise);
    vector<vector<uint>> maxPoints(n, vector<uint>(n, 0));

    maxPoints[0][0] = 1;
    for (uint i {1}; i < n; ++i)
        maxPoints[i][0] = 2;

    uint m {0};

    for (uint i {1}; i < n; ++i)
        m = max(m, findMaxPointsStartingAt(points, maxPoints, i));
    return m;
}

int main() { _
    uint n;

    for (uint test {1}; cin >> n and n; test++) {
        vector<Point> points;
        points.emplace_back(0, 0);

        while (n--) {
            uint x, y; cin >> x >> y;
            points.emplace_back(x, y);
        }

        cout << "Teste " << test << endl;
        cout << findMaxPoints(points) << endl;
        cout << endl;
    }
    
    return 0;
}
