#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
    int from, to, cost;
};

struct comparator {
    bool operator()(edge a, edge b) {
        return a.cost > b.cost;
    }
};

ifstream f("apm.in");
ofstream g("apm.out");

int n, m, a, b, c;
bool viz[200001];
vector<pair<int, int> > graph[200001];
vector<pair<int, int> > rez;
priority_queue<edge, vector<edge>, comparator> q;

void rezolvare() {
    for (auto &v:graph[1])
        q.push({1, v.first, v.second});
    edge sus;
    int cost = 0;
    while (!q.empty()) {
        sus = q.top();
        q.pop();
        if (!viz[sus.to]) {
            cost += sus.cost;
            rez.emplace_back(sus.from, sus.to);
            viz[sus.from] = viz[sus.to] = 1;
            for (auto &v:graph[sus.to]) {
                if (!viz[v.first]) {
                    q.push({sus.to, v.first, v.second});
                }
            }
        }
    }
    g << cost << '\n' << n - 1 << '\n';
    for (auto &v:rez)
        g << v.first << ' ' << v.second << '\n';
}
void citire(){
    f >> n >> m;
    for (int i = 1; i <= m; ++i) {
        f >> a >> b >> c;
        graph[a].emplace_back(b, c); graph[b].emplace_back(a, c);
    }
}


int main() {
    citire();
    rezolvare();
    return 0;
}
