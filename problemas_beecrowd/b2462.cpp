// https://www.beecrowd.com.br/judge/pt/problems/view/2462

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tempo_corrido(i, f) ((1440 + f - i) % 1440)

int str_time_to_houers(string& time) {
    string houers = time.substr(0, 2);
    string minuts = time.substr(3, 5);
    return 60 * stoi(houers) + stoi(minuts);
}

int main() { _
    int pa, cb, pb, ca;
    vector<int*> tempos {&pa, &cb, &pb, &ca};

    for (int i {0}; i < 4; i++) {
        string time;
        cin >> time;
        *tempos[i] = str_time_to_houers(time);
    }

    // delta_ab = tempo_voo + fuso * 60
    // delta_ba = tempo_voo - fuso * 60

    int delta_ab = tempo_corrido(pa, cb), delta_ba = tempo_corrido(pb, ca);
    int tempo_voo = ((delta_ab + delta_ba) / 2) % 720; // o voo nao pode ter mais de 12 horas
    int fuso = (delta_ab - tempo_voo) / 60;
    if (fuso > 12)
        fuso -= 24;

    cout << tempo_voo << " " << fuso << endl;

    return 0;
}
