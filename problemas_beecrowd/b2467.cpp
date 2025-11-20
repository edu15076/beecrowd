#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define MAX_VAL 51

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

class Tabuleiro {
public:
    explicit Tabuleiro(const int n, const int q): mN(n), mQ(q) {
        mLinhas = vector<pair<int, int8_t>>(mN, {0, 0});
        mColunas = vector<pair<int, int8_t>>(mN, {0, 0});

        mAtribuicoesLinhas = vector(MAX_VAL, ReverseBinTree(mQ));
        mAtribuicoesColunas = vector(MAX_VAL, ReverseBinTree(mQ));
    }

    void atribuirLinha(const int x, const int8_t r) {
        mAtribuirFileira(x, r, mLinhas, mAtribuicoesLinhas);
    }

    void atribuirColuna(const int x, const int8_t r) {
        mAtribuirFileira(x, r, mColunas, mAtribuicoesColunas);
    }

    int maxPosLinha(const int x) {
        return mMaxPosFileira(x, mLinhas, mAtribuicoesColunas);
    }

    int maxPosColuna(const int x) {
        return mMaxPosFileira(x, mColunas, mAtribuicoesLinhas);
    }

private:
    int mN, mQ, mMoment {0};

    vector<ReverseBinTree> mAtribuicoesLinhas, mAtribuicoesColunas;
    vector<pair<int, int8_t>> mLinhas, mColunas;

    void mAtribuirFileira(const int x, const int8_t r, vector<pair<int, int8_t>>& fileiras,
                                 vector<ReverseBinTree>& atribuicoes) {
        if (auto& [oldQ, oldR] = fileiras[x]; oldQ)
            atribuicoes[oldR].add(oldQ, -1);

        const int currentMoment = ++mMoment;
        fileiras[x].first = currentMoment;
        fileiras[x].second = r;
        atribuicoes[r].add(currentMoment, 1);
    }

    int mMaxPosFileira(const int x, const vector<pair<int, int8_t>>& fileiras,
                       vector<ReverseBinTree>& atribuicoesPerpendiculares) const {
        auto [momentoAtribuicaoFileira, rFileira] = fileiras[x];

        vector<int> fileiraFrequencia(MAX_VAL, 0);
        fileiraFrequencia[rFileira] = mN;

        for (int8_t r {0}; r < MAX_VAL; ++r) {
            const int frequenciaR = atribuicoesPerpendiculares[r].query(momentoAtribuicaoFileira + 1);
            fileiraFrequencia[rFileira] -= frequenciaR;
            fileiraFrequencia[r] += frequenciaR;
        }

        return 50 - (max_element(fileiraFrequencia.crbegin(), fileiraFrequencia.crend()) - fileiraFrequencia.crbegin());
    }
};

int main() { _
    int n, q; cin >> n >> q;

    Tabuleiro tabuleiro(n, q);

    for (int i {1}; i <= q; ++i) {
        int op, x; cin >> op >> x; --x;
        switch (op) {
            case 3:
                cout << tabuleiro.maxPosLinha(x) << endl;
                break;
            case 4:
                cout << tabuleiro.maxPosColuna(x) << endl;
                break;
            default:
                short r; cin >> r;
                if (op == 1)
                    tabuleiro.atribuirLinha(x, static_cast<int8_t>(r));
                else
                    tabuleiro.atribuirColuna(x, static_cast<int8_t>(r));
        }
    }

    return 0;
}
