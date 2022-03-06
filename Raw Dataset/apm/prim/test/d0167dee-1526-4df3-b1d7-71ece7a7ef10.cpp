#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;



struct muchie {

    int from, to, cost;

};



class comp {

public:

    bool operator()(muchie a, muchie b) {

        return a.cost > b.cost;

    }

};



ifstream f("apm.in");

ofstream g("apm.out");



int n, m, a, b, c;

bool vizitat[200001];

vector<pair<int, int> > graph[200001];

vector<pair<int, int> > rez;

priority_queue<muchie, vector<muchie>, comp> PQ;



void rezolvare() {

    for (auto &v:graph[1])

        PQ.push({1, v.first, v.second});

    muchie sus;

    int cost = 0;

    while (!PQ.empty()) {

        sus = PQ.top();

        PQ.pop();

        if (!vizitat[sus.to]) {

            cost += sus.cost;

            rez.emplace_back(sus.from, sus.to);

            vizitat[sus.from] = vizitat[sus.to] = 1;

            for (auto &v:graph[sus.to]) {

                if (!vizitat[v.first]) {

                    PQ.push({sus.to, v.first, v.second});

                }

            }

        }

    }

    g << cost << '\n';

    g << n - 1 << '\n';

    for (auto &v:rez)

        g << v.first << ' ' << v.second << '\n';

}

void citire(){

    f >> n >> m;

    for (int i = 1; i <= m; ++i) {

        f >> a >> b >> c;

        graph[a].emplace_back(b, c);

        graph[b].emplace_back(a, c);

    }

}





int main() {

    citire();

    rezolvare();

    return 0;

}
