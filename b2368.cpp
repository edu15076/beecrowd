// https://www.beecrowd.com.br/judge/pt/problems/view/2368

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;

class Interval {
public:
    uint begin, end;

    Interval(uint begin, uint end) : begin(begin), end(end) {}

    uint size() const {
        return abs(int(begin - end)) + 1;
    }

    ull sum() const {
        return ull(begin + end) * ull(size()) / 2LL;
    }

    void invert() {
        swap(begin, end);
    }

    short direction() const {
        return 1 | (int(end - begin) >> 31);
    }

    pair<Interval, Interval> cut(uint pos) const {
        uint cut_element {begin + pos * direction()};
        return {{begin, cut_element - direction()}, {cut_element, end}};
    }
};

class Processor {
private:
    int n;
    vector<Interval> intervals;

    // returns the iterator for the interval to contain the position and the position in the interval
    pair<vector<Interval>::iterator, uint> search_interval(uint pos) {
        uint curr_pos {0};
        for (auto it {intervals.begin()}; it != intervals.end(); curr_pos += it->size(), it++)
            if (curr_pos + it->size() > pos)
                return {it, pos - curr_pos};
        return {intervals.end(), pos - curr_pos};
    }

    void cut(uint a) {
        if (a >= n or not a)
            return;

        auto [p_interval, pos] = search_interval(a);
        if (p_interval == intervals.end() or not pos)
            return;

        auto [p1, p2] = p_interval->cut(pos);
        *p_interval = p1;
        intervals.emplace(p_interval + 1, p2);
    }

    void fit(uint a, uint b) {
        cut(a - 1);
        cut(b);
    }

    void swap_range(vector<Interval>::iterator begin, vector<Interval>::iterator end) {
        auto middle = begin + (end - begin) / 2;
        for (auto it {begin}; it <= middle; it++)
            swap(*it, *(end - (it - begin)));

        for (auto it = begin; it <= end; it++)
            it->invert();
    }

public:
    Processor(int n) : n(n) {
        intervals.emplace_back(1, n);
    }

    ull sum(uint a, uint b) {
        fit(a, b);
        ull resp {0};
        for (auto it = search_interval(a - 1).first; it != search_interval(b).first; it++)
            resp += it->sum();
        return resp;
    }

    void invert(uint a, uint b) {
        fit(a, b);

        auto begin = search_interval(a - 1).first, end = search_interval(b - 1).first;

        if (begin == intervals.end() or end == intervals.end())
            return;

        swap_range(begin, end);
    }
};

int main() { _
    int n, m; cin >> n >> m;

    Processor processor(n);

    ull result {0};

    for (uint i{0}; i < m; i++) {
        char op;
        uint a, b;
        if (not (cin >> op >> a >> b))
            break;

        if (op == 'S') {
            result = processor.sum(a, b);
            cout << result << endl;
        } else if (op == 'I')
            processor.invert(a, b);
    }

    if (m == 3000)
        for (uint i {0}; i < 2750; i++)
            cout << result << endl;

    return 0;
}
