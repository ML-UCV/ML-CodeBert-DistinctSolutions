#include <bits/stdc++.h>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



const int Dim = 4e5 + 5;

const int Inf = 1e9 + 5;



int dist[Dim], t[Dim];

int n, m, costTotal;



bool used[Dim];



vector <pair <int, int> > G[Dim], ans;

priority_queue <pair<int, int> > coada;



int main() {

    f >> n >> m;

    for(int i = 1; i <= m; ++i) {

        int x, y, cost;

        f >> x >> y >> cost;

        G[x].push_back({y, cost});

        G[y].push_back({x, cost});

    }



    for(int i = 1; i <= n; ++i) dist[i] = Inf;

    dist[1] = 0;



    coada.push({0, 1});

    while(!coada.empty()) {

        int node = coada.top().second;

        coada.pop();



        if(used[node] == false) {

            used[node] = true;

            costTotal += dist[node];

            if(t[node]) ans.push_back({node, t[node]});



            for(auto it = G[node].begin(); it != G[node].end(); ++it) {

                if(it -> second < dist[it -> first]) {

                    dist[it -> first] = it -> second;

                    t[it -> first] = node;

                    coada.push({-it -> second, it -> first});

                }

            }

        }

    }



    g << costTotal << '\n' << n - 1 << '\n';

    for(auto it = ans.begin(); it != ans.end(); ++it) {

        g << it -> first << " " << it -> second << '\n';

    }

    return 0;

}
