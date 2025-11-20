// https://www.beecrowd.com.br/judge/pt/problems/view/1084

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

template<typename T, typename = typename enable_if<is_arithmetic<T>::value, bool>::type>
class SegTree {
public:
    explicit SegTree(vector<T>& v) : mValues(v) {
        const size_t n = mValues.size();
        mSeg = vector<size_t>(4 * n, 0);

        // Starts on the root of the SegTree, 1 looking at the entire length of the vector
        mInit(1, 0, n - 1);
    }

    /**
     * Query for the smallest element index on the range that starts on i and ends on j, inclusive.
     * @param i The beginning index of the range, must be greater or equal to j.
     * @param j The ending index of the range.
     * @return The index of the minimum value in the range that starts on i and ends on j.
     */
    size_t query(const size_t& i, const size_t& j) {
        return mQuery(i, j, 1, 0, mValues.size() - 1);
    }

    void update(const size_t& i, const T& val) {
        mValues[i] = val;
        mUpdate(i, val, 1, 0, mValues.size() - 1);
    }

private:
    vector<size_t> mSeg;
    vector<T>& mValues;

    size_t mMinPositionIndexQuery(const size_t i, const size_t j) {
        if (i == -1)
            return j;
        else if (j == -1) // impossible for both to be -1
            return i;
        return mValues[i] >= mValues[j] ? i : j;
    }

    size_t mMinPositionIndex(const size_t i, const size_t j) {
        return mValues[i] >= mValues[j] ? i : j;
    }

    size_t mInit(const size_t pos, const size_t begin, const size_t end) {
        // If begin == end we are on a leaf and the minimum is the leaf itself
        if (begin == end)
            return mSeg[pos] = begin;

        const size_t half {(begin + end) / 2};

        // The pos on the SegTree that is not a leaf should be the minimum of
        return mSeg[pos] = mMinPositionIndex(mInit(2 * pos, begin, half),
                                             mInit(2 * pos + 1, half + 1, end));
    }

    size_t mQuery(const size_t i, const size_t j, const size_t pos, const size_t l, const size_t r) {
        if (j < l || r < i)
            return -1;

        if (i <= l && r <= j)
            return mSeg[pos];

        const size_t half {(l + r) / 2};
        return mMinPositionIndexQuery(mQuery(i, j, 2 * pos, l, half),
                                      mQuery(i, j, 2 * pos + 1, half + 1, r));
    }

    T mUpdate(const size_t i, const size_t pos, const size_t l, const size_t r) {
        if (i < l || r < i)
            return mSeg[pos];

        if (l == r) // l = r = i
            return mSeg[pos] = i;

        const size_t half {(l + r) / 2};
        return mSeg[pos] = mMinPositionIndex(mUpdate(i, 2 * pos, l, half),
                                             mUpdate(i, 2 * pos + 1, half + 1, r));
    }
};

int main() { _
    vector<uint> v {10, 2, 10, 4};
    SegTree<uint> s(v);
    cout << s.query(0, 3);
    
    return 0;
}
