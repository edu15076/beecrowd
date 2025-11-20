// https://www.beecrowd.com.br/judge/pt/problems/view/3057

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

void insertAxiomsForAllImplications(uint statement, vector<vector<uint>>& directImplications,
                                    vector<unordered_set<uint>>& axiomsForStatement, vector<bool>& visited, uint axiom) {
    visited[statement] = true;
    axiomsForStatement[statement].insert(axiom);

    for (auto implication : directImplications[statement])
        if (not visited[implication])
            insertAxiomsForAllImplications(implication, directImplications, axiomsForStatement, visited, axiom);
}

bool isSubSet(unordered_set<uint>& superSet, unordered_set<uint>& subSet) {
    if (superSet.size() < subSet.size())
        return false;
    for (auto item : subSet)
        if (superSet.find(item) == superSet.end())
            return false;
    return true;
}

void markImplicationsAsTrue(uint statement, vector<vector<uint>>& directImplications, vector<bool>& trueStatements) {
    stack<uint> s;
    s.push(statement);

    while (not s.empty()) {
        uint currStatement = s.top();
        s.pop();

        if (trueStatements[currStatement])
            continue;
        trueStatements[currStatement] = true;

        for (auto implication : directImplications[currStatement])
            s.push(implication);
    }
}

// Pior caso ocorre quando temos n/3 mustHaveAxioms e outros n/3 axiomas que não estão no mustHaveAxioms e
// temos que percorrer n/3 posições com ao menos n/3 axiomas de forma que o pior caso é da ordem O(n^2)
void makeIntersectionTrue(uint statement, vector<vector<uint>>& directImplications,
                          vector<unordered_set<uint>>& axiomsForStatement, unordered_set<uint>& mustHaveAxioms,
                          vector<bool>& trueStatements) {
    vector<bool> visited(axiomsForStatement.size(), false);
    stack<uint> s;
    s.push(statement);

    while (not s.empty()) {
        uint currStatement = s.top();
        s.pop();

        visited[currStatement] = true;
        if (trueStatements[currStatement])
            continue;
        if (isSubSet(axiomsForStatement[currStatement], mustHaveAxioms)) {
            markImplicationsAsTrue(currStatement, directImplications, trueStatements);
            continue;
        }

        for (auto implication : directImplications[currStatement])
            if (not visited[implication])
                s.push(implication);
    }
}

void statementIsTrue(uint statement, vector<bool>& trueStatements, vector<unordered_set<uint>>& axiomsForStatement,
                     vector<vector<uint>>& directImplications) {
    if (trueStatements[statement])
        return;

    markImplicationsAsTrue(statement, directImplications, trueStatements);

    if (axiomsForStatement[statement].empty())
        return;

    makeIntersectionTrue(*axiomsForStatement[statement].begin(), directImplications, axiomsForStatement,
                         axiomsForStatement[statement], trueStatements);
}

set<uint> vectorTrueToSet(const vector<bool>& v) {
    set<uint> s;
    for (uint i {0}, len = v.size(); i < len; ++i)
        if (v[i])
            s.insert(i);
    return s;
}

int main() {
    uint numberOfStatements, numberOfImplications, numberOfStatementsKnownToBeTrue;
    cin >> numberOfStatements >> numberOfImplications >> numberOfStatementsKnownToBeTrue;
    vector<vector<uint>> directImplications(numberOfStatements);

    unordered_set<uint> axioms;

    for (uint i {0}; i < numberOfStatements; ++i)
        axioms.insert(i);

    while (numberOfImplications--) {
        uint a, b; cin >> a >> b; a--; b--;
        directImplications[a].push_back(b);
        axioms.erase(b);
    }

    vector<unordered_set<uint>> axiomsForStatement(numberOfStatements);

    for (auto axiom : axioms) {
        vector<bool> visited(numberOfStatements, false);
        insertAxiomsForAllImplications(axiom, directImplications, axiomsForStatement, visited, axiom);
    }

    vector<bool> trueStatementsV(numberOfStatements, false);

    while (numberOfStatementsKnownToBeTrue--) {
        uint statementKnownToBeTrue; cin >> statementKnownToBeTrue; statementKnownToBeTrue--;
        statementIsTrue(statementKnownToBeTrue, trueStatementsV, axiomsForStatement, directImplications);
    }

    set<uint> trueStatements = vectorTrueToSet(trueStatementsV);

    auto last = trueStatements.empty() ? trueStatements.end() : prev(trueStatements.end());
    for (auto it = trueStatements.begin(); it != last; ++it)
        cout << *it + 1 << " ";
    if (not trueStatements.empty())
        cout << *last + 1 << endl;

    return 0;
}
