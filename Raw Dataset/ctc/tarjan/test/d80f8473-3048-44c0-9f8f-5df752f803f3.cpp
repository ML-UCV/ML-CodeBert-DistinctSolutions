#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;



ofstream out("ctc.out");
ifstream in("ctc.in");

int n, m;

vector<int> graph[100001];

int isStack[100001];

stack<int> s;

bool visited[100001];

int tm[100001];

int boss[100001];

int t = 0;

vector<int> sol[100001];

int sz = 0;

void dfsScc(int v) {
    visited[v] = true;

    t++;

    boss[v] = t;

    tm[v] = t;

    isStack[v] = true;

    s.push(v);

    for (int i = 0; i < graph[v].size(); i++) {
        if (!visited[graph[v][i]]) {
            dfsScc(graph[v][i]);
        }

        if (isStack[graph[v][i]] && boss[graph[v][i]] < boss[v]) {
            boss[v] = boss[graph[v][i]];
        }
    }

    if (tm[v] == boss[v]) {
        while (s.top() != v) {
            int curr = s.top();

            s.pop();

            isStack[curr] = false;

            sol[sz].push_back(curr + 1);


        }

        if (s.top() == v) {
            isStack[s.top()] = false;

            sol[sz].push_back(s.top() + 1);



            s.pop();
        }

        sz++;


    }
}

int main() {
    in >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;

        in >> u >> v;

        u--;

        v--;

        graph[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsScc(i);
        }
    }

    out << sz << '\n';

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sol[i].size(); j++) {
            out << sol[i][j] << " ";
        }

        out << '\n';
    }

    return 0;
}
