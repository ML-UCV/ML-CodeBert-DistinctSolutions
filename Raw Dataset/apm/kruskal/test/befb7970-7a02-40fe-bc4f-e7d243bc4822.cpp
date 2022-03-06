#include <bits/stdc++.h>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct edge {

    int x, y, cost;



    bool operator <(const edge &other) {

        return cost < other.cost;

    }

};



const int Dim = 4e5 + 5;



int tata[Dim], w[Dim];

int n, m, costTotal;



edge e[Dim];



vector <pair <int, int> > ans;



int findTata(int node) {

    int cn = node;

    while(tata[node] != node) {

        node = tata[node];

    }



    while(cn != node) {

        int aux = tata[cn];

        cn = aux;

        tata[cn] = node;

    }

    return node;

}



void uneste(int node1, int node2) {

    int t1 = findTata(node1);

    int t2 = findTata(node2);



    if(w[t1] < w[t2]) {

        tata[t1] = t2;

        w[t2] += w[t1];

    } else {

        tata[t2] = t1;

        w[t1] += w[t2];

    }

}



int main() {

    f >> n >> m;

    for(int i = 1; i <= m; ++i) {

        f >> e[i].x >> e[i].y >> e[i].cost;

    }



    for(int i = 1; i <= n; ++i) {

        tata[i] = i;

        w[i] = 1;

    }



    sort(e + 1, e + m + 1);

    for(int i = 1; i <= m; ++i) {

        if(findTata(e[i].x) != findTata(e[i].y)) {

            uneste(e[i].x, e[i].y);

            costTotal += e[i].cost;

            ans.push_back({e[i].x, e[i].y});

        }

    }



    g << costTotal << '\n' << n - 1 << '\n';

    for(auto it = ans.begin(); it != ans.end(); ++it) {

        g << it -> first << " " << it -> second << '\n';

    }

    return 0;

}
