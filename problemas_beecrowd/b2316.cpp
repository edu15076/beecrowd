// https://www.beecrowd.com.br/judge/pt/problems/view/2316

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 1'000'000

#define laps(car) get<0>(car)
#define checkPoint(car) get<1>(car)
#define time(car) get<2>(car)

typedef unsigned uint;

struct CompareCars {
    bool operator()(const tuple<int, int, int>& c1, const tuple<int, int, int>& c2) const {
        if (laps(c1) != laps(c2))
            return laps(c1) > laps(c2);
        if (checkPoint(c1) != checkPoint(c2))
            return checkPoint(c1) > checkPoint(c2);
        return time(c1) < time(c2);
    }
};

void updateCarStatus(tuple<int, int, int>& car, uint p, uint t, uint k) {
    if ((checkPoint(car) + 1) % k != p)
        return;
    checkPoint(car) = p;
    laps(car) += not p;
    time(car) = t;
}

int main() { _
    uint k, n, m; cin >> k >> n >> m;
    vector cars(n, tuple<int, int, int>(0, -1, INF));

    for (uint t {0}; t < m; t++) {
        uint x, y; cin >> x >> y; x--; y--;
        updateCarStatus(cars[x], y, t, k);
    }

    map<tuple<int, int, int>, uint, CompareCars> orderedCars;

    for (uint i {0}; i < n; i++)
        orderedCars[cars[i]] = i + 1;

    vector<uint> positions;

    for (auto& [status, car] : orderedCars)
        positions.push_back(car);

    for (auto it = positions.begin(); it < positions.end() - 1; it++)
        cout << *it << " ";
    cout << positions.back() << endl;

    return 0;
}
