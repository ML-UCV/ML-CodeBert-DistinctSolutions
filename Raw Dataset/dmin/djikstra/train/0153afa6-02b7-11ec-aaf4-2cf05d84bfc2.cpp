#include <bits/stdc++.h>
using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");
int n;



vector < pair < int , double > > g[1510];

double d[1510];

int solutie[1510];

bool viz[1510];



struct cmp {

    bool operator()(int a, int b) {

        return d[a] > d[b];

    }

};



priority_queue < int, vector < int >, cmp > c;



void read() {

    int m;

    fin >> n >> m;

    while(m--) {

        int x, y, cost;

        fin >> x >> y >> cost;

        g[x].push_back({y, (double) log2((double)cost)});

        g[y].push_back({x, (double) log2((double)cost)});

    }

}



void DJ(int nod) {



    for(int i=1; i<=n; i++) {

        d[i] = INT_MAX;

    }



    c.push(nod);

    d[nod] = 0;

    viz[nod] = 1;

    solutie[1] = 1;



    while(!c.empty()) {

            int nod = c.top();

            c.pop();

            viz[nod] = 0;



            for(size_t i = 0; i < g[nod].size(); i++) {

                int vecin = g[nod][i].first;

                double cost = g[nod][i].second;



                if(d[vecin] > d[nod] + cost || (d[vecin] < d[nod] + cost + 1e-9 && d[vecin] > d[nod] + cost - 1e-9)) {



                    if(d[vecin] < d[nod] + cost + 1e-9 && d[vecin] > d[nod] + cost - 1e-9) {

                        solutie[vecin] = (solutie[vecin] + solutie[nod]) % 104659;

                    } else {

                        solutie[vecin] = solutie[nod] % 104659;

                        if(viz[vecin] == 0) {

                            c.push(vecin);

                            viz[vecin] = 1;

                        }

                        d[vecin] = d[nod] + cost;

                    }

                }

            }

     }

}





void solve() {

    DJ(1);



    for(int i=2; i<=n; i++) {

        fout << solutie[i] % 104659 << " ";

    }

}



int main() {

    read();

    solve();

}
