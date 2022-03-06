#include <bits/stdc++.h>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



const int Dim = 4e5 + 5;



struct edge {

    int x, y, cost;

    bool operator <(const edge &other) {

        return cost < other.cost;

    }

};



int n, m, costTotal;

int tata[Dim], w[Dim];



edge e[Dim];



vector <pair<int, int> > ans;



int findTata(int node) {

    int cn = node;

    while(tata[cn] != cn) {

        cn = tata[cn];

    }



    while(node != cn) {

        int aux = node;

        tata[node] = cn;

        node = tata[aux];

    }

    return node;

}



void uneste(int node1, int node2) {

    int tNode1 = findTata(node1);

    int tNode2 = findTata(node2);

    if(w[tNode1] < w[tNode2]) {

        tata[tNode1] = tNode2;

        w[tNode2] += w[tNode1];

    } else {

        tata[tNode2] = tNode1;

        w[tNode1] += w[tNode2];

    }

}



int main() {

    f >> n >> m;

    for(int i = 1; i <= m; ++i) {

        f >> e[i].x >> e[i].y >> e[i].cost;

    }



    sort(e + 1, e + m + 1);

    for(int i = 1; i <= n; ++i) {

        w[i] = 1;

        tata[i] = i;

    }



    for(int i = 1; i <= m; ++i) {

        if(findTata(e[i].x) != findTata(e[i].y)) {

            uneste(e[i].x, e[i].y);

            ans.push_back({e[i].x, e[i].y});

            costTotal += e[i].cost;

        }

    }



    g << costTotal << '\n' << n - 1 << '\n';

    for(auto it = ans.begin(); it != ans.end(); ++it) {

        g << it -> first << " " << it -> second << '\n';

    }

    return 0;

}
