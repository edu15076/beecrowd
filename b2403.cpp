// https://www.beecrowd.com.br/judge/pt/problems/view/2403

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define VISITADO -1

typedef unsigned uint;

bool wereAllTarefasVisited(const vector<int>& tarefas) {
    for (auto tarefa : tarefas)
        if (tarefa != VISITADO)
            return false;
    return true;
}

int main() { _
    uint n, m; cin >> n >> m;

    vector<vector<uint>> tarefas(n);
    vector<int> grau(n, 0);

    unordered_set<uint> tarefasGrau0;
    for (uint i {0}; i < n; ++i)
        tarefasGrau0.insert(i);

    while (m--) {
        uint a, b; cin >> a >> b;
        tarefas[a].push_back(b);
        grau[b]++;
        tarefasGrau0.erase(b);
    }

    vector<uint> escalonamento;

    priority_queue<uint, vector<uint>, greater<>> pq;
    for (auto tarefa : tarefasGrau0)
        pq.push(tarefa);

    while (not pq.empty()) {
        auto tarefa = pq.top();
        pq.pop();

        grau[tarefa] = VISITADO;
        escalonamento.push_back(tarefa);

        for (auto t : tarefas[tarefa]) {
            if (grau[t] == VISITADO)
                continue;
            grau[t]--;
            if (not grau[t])
                pq.push(t);
        }
    }

    if (not wereAllTarefasVisited(grau)) {
        cout << "*" << endl;
        return 0;
    }

    for (auto tarefa : escalonamento)
        cout << tarefa << endl;
    
    return 0;
}
