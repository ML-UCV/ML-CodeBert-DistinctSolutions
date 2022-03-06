#include<fstream>
#include<vector>
#include<cmath>
#include<queue>


using namespace std;

typedef int64_t var;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



struct Edge {

    var n, c;

    Edge(var a, var b) {

        n = a;

        c = b;

    }

};





vector<Edge> G[1505];

var n;

double D[1505];

var D_R[1505];

var NR[1505];

bool INQ[1505];
void bellman() {

    for(var i=1; i<=n; i++) {

        D[i] = (1LL << 55);

    }

    D[1] = 0;

    NR[1] = 1;

    queue<var> Q;

    Q.push(1);

    while(!Q.empty()) {

        var node = Q.front();

        Q.pop();

        INQ[node] = 0;

        for(auto e : G[node]) {

            if((D[e.n] > D[node] + log10(e.c) + 1e-12)) {

                D[e.n] = D[node] + log10(e.c);

                D_R[e.n] = (D_R[node] * e.c) % 10000;

                NR[e.n] = 0;

                if(!INQ[e.n]) {

                    Q.push(e.n);

                    INQ[e.n] = 1;

                }

            }

            if(abs(D[e.n] - (D[node] + log10(e.c))) < 1e-12 && D_R[e.n] == (D_R[node] * e.c) % 10000 ) {

                NR[e.n] += NR[node];

                NR[e.n] %= 104659;

            }

        }

    }

}



int main() {

    var a, b, m;

    var c;

    fin>>n>>m;

    while(m--) {

        fin>>a>>b>>c;

        G[a].push_back(Edge(b, c));

        G[b].push_back(Edge(a, c));

    }

    bellman();

    for(var i=2; i<=n; i++) {

        fout<<NR[i]<<" ";

    }

    return 0;

}
