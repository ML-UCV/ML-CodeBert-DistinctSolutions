#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>




using namespace std;

int N;

vector< vector< pair< int, double> > > G;

vector<long long> nrd;

vector<double> dmin;



int comp(double x, double y) {

    double abs = x - y;

    if(abs < 0)

        abs = -abs;

    if(abs < 0.000000001)

        return 0;

    if(x > y)

        return 1;

    if(x < y)

        return -1;

}

void BellmanFord() {

    queue<int> Q;

    vector<bool> inQueue; inQueue.assign(N + 1, 0);

    dmin[1] = 0;

    nrd[1] = 1;

    Q.push(1);

    inQueue[1] = 1;

    while(!Q.empty()) {

        int node = Q.front(); Q.pop();

        inQueue[node] = 0;

        for(int i = 0; i < G[node].size(); i++) {

            int neigh = G[node][i].first;

            double cost = G[node][i].second;

            if(comp(dmin[neigh], dmin[node] + cost + 0.000000001) > 0) {

                dmin[neigh] = dmin[node] + cost;

                nrd[neigh] = nrd[node];

                if(!inQueue[neigh]) {

                    Q.push(neigh);

                    inQueue[neigh] = 1;

                }

            }

            else if(comp(dmin[neigh], dmin[node] + cost) == 0) {

                nrd[neigh] = (nrd[node] % 104659 + nrd[neigh] % 104659 ) % 104659;

                if(!inQueue[neigh]) {

                    inQueue[neigh] = 1; Q.push(neigh);

                }

            }

        }

    }

}



int main()

{

    freopen("dmin.in", "rt", stdin);

    freopen("dmin.out", "wt", stdout);

    int M;

    scanf("%d%d", &N, &M);

    G.assign(N + 2, vector<pair<int, double> >());

    while(M--) {

        int a, b, c;

        scanf("%d%d%d", &a, &b, &c);

        G[a].push_back(make_pair(b, log(c)));

    }

    dmin.assign(N + 2, INT_MAX);

    nrd.assign(N + 2, 0);

    BellmanFord();

    for(int i = 2; i <= N; i++)

        cout << nrd[i] % 104659 << ' ';

    cout << '\n';





    return 0;

}
