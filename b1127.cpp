// https://www.beecrowd.com.br/judge/pt/problems/view/1127

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

class Solution {
public:
    map<string, short> semitone {
            {"Cb", 12}, {"C", 1}, {"C#", 2},
            {"Db", 2}, {"D", 3}, {"D#", 4},
            {"Eb", 4}, {"E", 5}, {"E#", 6},
            {"Fb", 5}, {"F", 6}, {"F#", 7},
            {"Gb", 7}, {"G", 8}, {"G#", 9},
            {"Ab", 9}, {"A", 10}, {"A#", 11},
            {"Bb", 11}, {"B", 12}, {"B#", 1}
    };

    string original, copy;

    Solution(const vector<string>& original, const vector<string>& copy) {
        this->original = semitonesDist(original);
        this->copy = semitonesDist(copy);
    }

    bool isCopy() {
        return original.find(copy) != string::npos;
    }

private:
    string semitonesDist(const vector<string>& music) {
        char* d = (char*) malloc(music.size());
        d[music.size() - 1] = '\0';
        for (auto it = music.begin() + 1; it < music.end(); it++)
            d[it - music.begin() - 1] = ((int) semitone[*it] - (int) semitone[*(it - 1)] + 12) % 12 + 'M';
        return {d};
    }
};

int main() { _
    for (uint m, t; cin >> m >> t and m and t; ) {
        vector<string> original(m), copy(t);
        for (auto& note : original)
            cin >> note;
        for (auto& note : copy)
            cin >> note;

        cout << (Solution(original, copy).isCopy() ? "S" : "N") << endl;
    }

    return 0;
}
