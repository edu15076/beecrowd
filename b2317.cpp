// https://www.beecrowd.com.br/judge/pt/problems/view/2317

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define sheep first
#define wolves second

typedef unsigned uint;

vector<pair<int, int>> moves {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pair<uint, uint> countAnimals(vector<vector<char>>& fazenda, pair<uint, uint> pos) {
    pair<uint, uint> animals {0, 0};

    queue<pair<uint, uint>> q;
    q.push(pos);

    while (not q.empty()) {
        auto p = q.front();
        q.pop();

        switch (fazenda[p.first][p.second]) {
            case '#':
                continue;
            case 'k':
                animals.sheep++;
                break;
            case 'v':
                animals.wolves++;
        }

        fazenda[p.first][p.second] = '#';

        for (auto move : moves) {
            pair<uint, uint> nextPos {move.first + p.first, move.second + p.second};
            if (fazenda[nextPos.first][nextPos.second] != '#')
                q.push(nextPos);
        }
    }

    return animals;
}

pair<uint, uint> remainingAnimals(vector<vector<char>>& fazenda, pair<uint, uint> pos) {
    auto animals = countAnimals(fazenda, pos);
    if (animals.sheep > animals.wolves)
        animals.wolves = 0;
    else
        animals.sheep = 0;
    return animals;
}

int main() { _
    uint r, c; cin >> r >> c;
    vector fazenda(r + 2, vector<char>(c + 2, '#'));

    for (auto line = fazenda.begin() + 1; line < fazenda.end() - 1; line++)
        for (auto it = line->begin() + 1; it < line->end() - 1; it++)
            cin >> *it;

    pair<uint, uint> animals {0, 0};

    for (uint i {1}; i <= r; i++)
        for (uint j {1}; j <= c; j++) {
            auto remainingAnimalsInField = remainingAnimals(fazenda, {i, j});
            animals.sheep += remainingAnimalsInField.sheep;
            animals.wolves += remainingAnimalsInField.wolves;
        }

    cout << animals.sheep << " " << animals.wolves << endl;
    
    return 0;
}
