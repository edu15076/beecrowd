// https://www.beecrowd.com.br/judge/pt/problems/view/2319

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 1'000'000

typedef unsigned uint;

uint countExpFactor(int num, int factor) {
    int count {0};
    for ( ; not (num % factor); count++, num /= factor);
    return count;
}

class TwoFiveExp {
public:
    TwoFiveExp(int n) {
        two = countExpFactor(n, 2);
        five = countExpFactor(n, 5);
    }

    TwoFiveExp(uint two, uint five) {
        this->two = two;
        this->five = five;
    }

    uint numberOfZeros() const {
        return min(two, five);
    }

    TwoFiveExp operator*(const TwoFiveExp& other) const {
        return {two + other.two, five + other.five};
    }

    uint two, five;
};

class Solution {
public:
    Solution(const vector<vector<int>>& board) : n(board.size()), board(board) {
        line = vector(n + 1, TwoFiveExp(INF, INF));
        lineBefore = vector(n + 1, TwoFiveExp(INF, INF));

        lineBefore[1] = TwoFiveExp(0, 0);
    }

    uint findMinPenalty() {
        for (uint i {1}; i <= n; i++) {
            for (uint j {1}; j <= n; j++)
                if (board[i - 1][j - 1]) updatePos(i, j);
            prepareNextIteration();
        }

        return lineBefore[n].numberOfZeros();
    }

private:
    const vector<vector<int>>& board;
    vector<TwoFiveExp> line, lineBefore;
    uint n;

    void prepareNextIteration() {
        for (uint i {0}; i <= n; i++) {
            lineBefore[i] = line[i];
            line[i] = TwoFiveExp(INF, INF);
        }
        line[0] = TwoFiveExp(INF, INF);
    }

    void updatePos(uint i, uint j) {
        auto &up = lineBefore[j], &left = line[j - 1];
        auto e = TwoFiveExp(board[i - 1][j - 1]);
        line[j] = e * TwoFiveExp(min(up.two, left.two), min(up.five, left.five));
    }
};

int main() { _
    int n; cin >> n;
    vector board(n, vector<int>(n));

    for (auto& line : board)
        for (auto& item : line)
            cin >> item;

    cout << Solution(board).findMinPenalty() << endl;

    return 0;
}
