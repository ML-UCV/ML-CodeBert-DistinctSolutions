#include <bits/stdc++.h>


using namespace std;



int const CAP = 200001;



struct Edge {

    int from;

    int to;

    int cost;



    bool operator < (Edge e) const {

        if (cost != e.cost) {

            return cost < e.cost;

        } else if (to != e.to) {

            return to < e.to;

        }

        return from < e.from;

    }

};



int n, m;

vector<Edge> g;

int boss[CAP];

int sz[CAP];



int sol = 0;

vector<Edge> solEdges;



void setUpNode(int curr) {

    boss[curr] = curr;

    sz[curr] = 1;

}



int getBoss(int curr) {

    if (boss[curr] != curr) {

        boss[curr] = getBoss(boss[curr]);

    }



    return boss[curr];

}



void combineComponents(int fromBoss, int toBoss) {

    if (sz[fromBoss] < sz[toBoss]) {

        boss[fromBoss] = toBoss;



        sz[toBoss] += sz[fromBoss];

    }



    else {

        boss[toBoss] = fromBoss;



        sz[fromBoss] += sz[toBoss];

    }

}



ofstream out("apm.out");

ifstream in("apm.in");



int main() {

    in >> n >> m;



    for (int i = 0; i < m; i++) {

        int x, y, c;

        in >> x >> y >> c;



        g.push_back({x, y, c});

    }



    sort(g.begin(), g.end());



    for (int i = 0; i < n; i++) {

        setUpNode(i);

    }



    for (int i = 0; i < m; i++) {

        int fromBoss = getBoss(g[i].from);



        int toBoss = getBoss(g[i].to);



        if (fromBoss != toBoss) {

            combineComponents(fromBoss, toBoss);



            sol += g[i].cost;



            solEdges.push_back(g[i]);

        }

    }



    out << sol << "\n" << solEdges.size() << "\n";



    for(int i=0; i<solEdges.size(); i++) {

        out << solEdges[i].from << " " << solEdges[i].to << "\n";

    }



    return 0;

}
