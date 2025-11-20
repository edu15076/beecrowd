// https://www.beecrowd.com.br/judge/pt/problems/view/2570

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

#define MAX_VAL 5

typedef unsigned uint;

class BinTree {
public:
    explicit BinTree(int n) {
        mBin = vector(n + 1, 0);
    }

    void add(int p, const int val) {
        // p & -p retorna a maior potência de 2 divisora de p
        for (auto size = mBin.size(); p < size; p += p & -p)
            mBin[p] += val;
    }

    int query(int p) {
        int sumToP {0};
        for ( ; p > 0; p -= p & -p)
            sumToP += mBin[p];
        return sumToP;
    }

protected:
    vector<int> mBin;
};

/**
 * Possibilita consultar e salvar a soma de uma posição até o fim
 */
class ReverseBinTree : public BinTree {
public:
    explicit ReverseBinTree(int n) : BinTree(n) {};

    void add(int p, const int val) {
        BinTree::add(static_cast<int>(mBin.size()) - p, val);
    }

    int query(int p) {
        return BinTree::query(static_cast<int>(mBin.size()) - p);
    }
};

class Grid {
public:
    explicit Grid(const int n, const int m, const int k): mN(n), mM(m), mK(k) {
        mLinhas = vector<pair<int, char>>(mN, {0, 0});
        mColunas = vector<pair<int, char>>(mM, {0, 0});

        mAtribuicoesLinhas = vector(MAX_VAL, ReverseBinTree(mK));
        mAtribuicoesColunas = vector(MAX_VAL, ReverseBinTree(mK));
    }

    void atribuirLinha(const int x, const char r) {
        mAtribuirFileira(x, r, mLinhas, mAtribuicoesLinhas);
    }

    void atribuirColuna(const int x, const char r) {
        mAtribuirFileira(x, r, mColunas, mAtribuicoesColunas);
    }

    vector<int> countFrequencias() {
        return mCountAllElements();
    }

private:
    int mN, mM, mK, mMoment {0};

    vector<ReverseBinTree> mAtribuicoesLinhas, mAtribuicoesColunas;
    vector<pair<int, char>> mLinhas, mColunas;

    void mAtribuirFileira(const int x, const char r, vector<pair<int, char>>& fileiras,
                          vector<ReverseBinTree>& atribuicoes) {
        if (auto& [oldQ, oldR] = fileiras[x]; oldQ)
            atribuicoes[oldR].add(oldQ, -1);

        const int currentMoment = ++mMoment;
        fileiras[x].first = currentMoment;
        fileiras[x].second = r;
        atribuicoes[r].add(currentMoment, 1);
    }

    vector<int> mCountItemsFileira(const int x, const vector<pair<int, char>>& fileiras,
                                   vector<ReverseBinTree>& atribuicoesPerpendiculares, int size) const {
        auto [momentoAtribuicaoFileira, rFileira] = fileiras[x];

        vector<int> fileiraFrequencia(MAX_VAL, 0);
        fileiraFrequencia[rFileira] = size;

        for (char r {0}; r < MAX_VAL; ++r) {
            const int frequenciaR = atribuicoesPerpendiculares[r].query(momentoAtribuicaoFileira + 1);
            fileiraFrequencia[rFileira] -= frequenciaR;
            fileiraFrequencia[r] += frequenciaR;
        }

        return fileiraFrequencia;
    }
    
    vector<int> mCountAllElements() {
        vector<int> frequencias(MAX_VAL, 0);
        
        for (uint i {0}; i < mN; i++) {
            auto frequenciasLine = mCountItemsFileira(i, mLinhas, mAtribuicoesColunas, mM);
            for (uint r {0}; r < MAX_VAL; r++)
                frequencias[r] += frequenciasLine[r];
        }

        return frequencias;
    }
};

int main() { _
    int n, m, k; cin >> n >> m >> k;
    Grid grid = Grid(n, m, k);

    char turn {1};

    for (; k--; turn = turn % 4 + 1) {
        char move;
        uint pos;
        cin >> move >> pos; pos--;

        if (move == 'L')
            grid.atribuirLinha(pos, turn);
        else
            grid.atribuirColuna(pos, turn);
    }

    auto frequencias = grid.countFrequencias();

    int r {frequencias[1]}, h {frequencias[2]}, c {frequencias[3]}, p {frequencias[4]};

    cout << "R" << r << " H" << h << " C" << c << " P" << p << endl;
    
    return 0;
}
