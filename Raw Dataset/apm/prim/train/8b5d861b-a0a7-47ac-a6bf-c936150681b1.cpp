#include <bits/stdc++.h>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



priority_queue < pair < int , int > , vector < pair < int , int > > , greater < pair < int , int > > > pq;

int tat[200005],dist[200005];

vector < pair < int , int > > v[200005];

int n,m;

int x,y,cost;

int oo=2000000009;

bool viz[200005];

int sumdist;



int main()

{

    f >> n >> m;

    for (int i=1;i<=m;i++) {

        f >> x >> y >> cost;

        v[x].push_back(make_pair(y,cost));

        v[y].push_back(make_pair(x,cost));

    }

    for (int i=2;i<=n;i++) {

        dist[i]=oo;

    }

    pq.push(make_pair(0,1));

    while (pq.empty()==0) {

        int nod = pq.top().second;

        int distnod = pq.top().first;

        pq.pop();

        if (viz[nod]==0) {

            viz[nod] = 1;

            sumdist += distnod;

            for (int i=0;i<v[nod].size();i++) {

                int nodtoviz = v[nod][i].first;

                int disttoviz = v[nod][i].second;

                if (dist[nodtoviz] > disttoviz && viz[nodtoviz] == 0) {

                    dist[nodtoviz] = disttoviz;

                    pq.push(make_pair(disttoviz,nodtoviz));

                    tat[nodtoviz] = nod;

                }

            }

        }

    }

    g << sumdist << '\n' << n-1 << '\n';

    for (int i=2;i<=n;i++) {

        g << i << " " << tat[i]<<'\n';

    }

    return 0;

}
