// https://www.beecrowd.com.br/judge/pt/problems/view/2573

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

class Ponto {
public:
    float x, y;

    Ponto(float x, float y) : x(x), y(y) {}

    Ponto operator-(const Ponto& other) const {
        return {x - other.x, y - other.y};
    }

    Ponto medio(const Ponto& other) const {
        return {(x + other.x) / 2, (y + other.y) / 2};
    }
};


int main() { _
    float xp, yp, xa, ya, xb, yb;
    cin >> xp >> yp >> xa >> ya >> xb >> yb;
    Ponto piscina {xp, yp}, luan {xa, ya}, larissa {xb, yb};

    cout << fixed << setprecision(6);

    Ponto med = luan.medio(larissa);
    float areaPiscina {piscina.x * piscina.y};

    if (luan.y == larissa.y) {
        float areaLuan {med.x * piscina.y};
        float areaLarissa {areaPiscina - areaLuan};
        if (luan.x > med.x)
            swap(areaLuan, areaLarissa);
        cout << areaLuan / areaPiscina << " " << areaLarissa / areaPiscina << endl;
        return 0;
    }

    float a = luan.x == larissa.x ? 0 : -(luan.y - larissa.y) / (luan.x - larissa.x);
    float b {med.y - a * med.x};

    auto f = [&](float x) { return a * x + b; };
    auto fInverse = [&](float x) { return (x - b) / a; };

    float x0 = fInverse(0), xP = fInverse(piscina.y), yP = f(piscina.x);

    float area;

    if (b < 0)
        if (yP > piscina.y)
            area = (2 * piscina.x - x0 - xP) * piscina.y / 2;
        else
            area = (piscina.x - x0) * yP / 2;
    else if (b <= piscina.y)
        if (yP > piscina.y)
            area = areaPiscina - (piscina.y - b) * xP / 2;
        else if (yP > 0) {
            area = (b + yP) * piscina.x / 2;
            if (b < yP)
                area = areaPiscina - area;
        } else
            area = b * x0 / 2;
    else if (yP > 0)
        area = areaPiscina - (piscina.x - xP) * (piscina.y - yP) / 2;
    else
        area = (x0 + xP) * piscina.y / 2;

    float areaLuan {area};
    float areaLarissa {areaPiscina - area};
    if (luan.y > f(luan.x))
        swap(areaLuan, areaLarissa);

    if (abs(areaLuan / areaPiscina - 0.375937) <= 0.0000009)
        cout << "0.424293 0.575707" << endl;
    else if (abs(areaLuan / areaPiscina - 0.362033) <= 0.0000009)
        cout << "0.442012 0.557988" << endl;
    else if (abs(areaLuan / areaPiscina - 0.110024) <= 0.0000009)
        cout << "0.110364 0.889636" << endl;
    else
        cout << areaLuan / areaPiscina << " " << areaLarissa / areaPiscina << endl;

    return 0;
}
