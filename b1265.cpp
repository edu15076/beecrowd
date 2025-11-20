// https://www.beecrowd.com.br/judge/pt/problems/view/1265

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;
typedef unsigned short ushort;
typedef unsigned long long ull;
typedef long long ll;

char char_for_digit(uint16_t digit) {
    return digit + 'A';
}

void _int_to_string(ull n, ull base, stringstream& ss) {
    if (not n)
        return;
    _int_to_string(n / base, base, ss);
    ss << char_for_digit(n % base);
}

string int_to_string(ull n, ull base) {
    if (not n)
        return "A";
    stringstream ss;
    _int_to_string(n, base, ss);
    return ss.str();
}

char query(ull n, ull pos) {
    ull number_of_digits {1};
    for (ull n_pow {n}; pos > n_pow * number_of_digits; n_pow *= n, number_of_digits++)
        pos -= n_pow * number_of_digits;
    ull number {(pos - 1) / number_of_digits};
    pos = (pos - 1) % number_of_digits;
    string s = int_to_string(number, n);
    if (s.length() < number_of_digits - pos)
        return 'A';
    pos -= number_of_digits - s.length();
    return s[pos];
}

int main() { _
    ull n, q;

    while (cin >> n >> q and n and q) {
        vector<string> musics(n);
        for (auto &music : musics)
            cin >> music;
        while (q--) {
            ull pos; cin >> pos;
            cout << musics[query(n, pos) - 'A'] << endl;
        }

        cout << endl;
    }
    
    return 0;
}
