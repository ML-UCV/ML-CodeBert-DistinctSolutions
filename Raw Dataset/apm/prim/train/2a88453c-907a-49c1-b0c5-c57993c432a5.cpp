#include <bits/stdc++.h>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



priority_queue < pair < int , int > , vector < pair < int , int > > , greater < pair < int , int > > > q;

vector < pair < int , int > > v[200100];

int totaldist,n,viz[200100],dist[200100],tata[200100];

int m,i,x,y,cost;

int oo=2000000009;



int main()

{

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        f>>x>>y>>cost;

        v[x].push_back(make_pair(y,cost));

        v[y].push_back(make_pair(x,cost));

    }

     for(int i=1;i<=n;i++) {

            dist[i]=oo;

    }

    dist[1]=0;

    q.push(make_pair(0,1));

        while(q.empty()==0) {

        int nod = q.top().second;

        int distnod = q.top().first;

        q.pop();

        if(viz[nod]==0) {

            viz[nod] = 1;

            totaldist += distnod;

            for (int i=0;i<v[nod].size();i++) {

                int nodtoviz = v[nod][i].first;

                int distance = v[nod][i].second;

                if(dist[nodtoviz] > distance && viz[nodtoviz]==0) {

                    dist[nodtoviz] = distance;

                    q.push(make_pair(dist[nodtoviz],nodtoviz));

                    tata[nodtoviz] = nod;

                }

            }

        }

    }

    g << totaldist << '\n';

    g << n-1 << '\n';

    for (i=1;i<=n;i++) {

        if (tata[i]!=0) {

            g << i << " " << tata[i] << '\n';

        }

    }

    return 0;

}
