// https://www.beecrowd.com.br/judge/pt/problems/view/2465

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define line first
#define column second
#define value first
#define visited second

typedef unsigned int uint;

template <typename T>
using matrix = vector<vector<T>>;

vector<pair<int, bool>> inputVector(uint size) {
    vector<pair<int, bool>> v(size, {0, false});
    for (uint i {0}; i < size; i++)
        cin >> v[i].first;
    return v;
}

matrix<pair<int, bool>> inputMatrix(uint numLines, uint numColumns) {
    matrix<pair<int, bool>> m(numLines);
    for (uint i {0}; i < numLines; i++)
        m[i] = inputVector(numColumns);
    return m;
}

vector<pair<int, int>> moveDirections = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int bandeirasLevantadas {0};

bool isMoveInBounds(pair<int, int>& move, size_t size) {
    return move.line >= 0 && move.column >= 0 && move.line < size && move.column < size;
}

void alunoAction(matrix<pair<int, bool>>& alunos, pair<int, int> alunoPos) {
    pair<int, bool>& aluno = alunos[alunoPos.line][alunoPos.column];
    aluno.visited = true;
    bandeirasLevantadas++;
    for (auto moveDirection : moveDirections) {
        pair<int, int> move {alunoPos.line + moveDirection.line, alunoPos.column + moveDirection.column};
        if (!isMoveInBounds(move, alunos.size()))
            continue;
        pair<int, bool> alunoMoved = alunos[move.line][move.column];
        if (!alunoMoved.visited && alunoMoved.value >= aluno.value)
            alunoAction(alunos, move);
    }
}

int main() {
    int n, i, j; cin >> n >> i >> j;
    matrix<pair<int, bool>> alunos = inputMatrix(n, n);
    alunoAction(alunos, {i - 1, j - 1});
    cout << bandeirasLevantadas << endl;

    return 0;
}
