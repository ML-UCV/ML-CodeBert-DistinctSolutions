#include <bits/stdc++.h>
using namespace std;



int egal(double,double);

void read();

void bellmanford();

vector <pair <int,double> > G[1505];

int nrd[1505],inQueue[1505],n,m;

double dmin[1505];

int main(){

    read();

    bellmanford();

    freopen("dmin.out","w",stdout);

    for (int i=2;i<=n;i++){

        cout<<nrd[i]%104659<<' ';

    }

}



void bellmanford(){

    dmin[1]=0;

    for (int i=2;i<=n;i++){

        dmin[i]=(int)2e9;

    }

    queue <int> q;

    q.push(1);

    nrd[1]=1;

    inQueue[1]=1;

    while (!q.empty()){

        int nod=q.front();

        inQueue[nod]=0;

        q.pop();

        for (int i=0;i<G[nod].size();i++){

            int vecin=G[nod][i].first;

            double cost=G[nod][i].second;

            if (dmin[vecin]>dmin[nod]+cost+1e-9){

                nrd[vecin]=nrd[nod]%104659;

                dmin[vecin]=dmin[nod]+cost;

                if (!inQueue[vecin]){

                    q.push(vecin);

                    inQueue[vecin]=1;

                }

            }

            else {

                if (egal(dmin[vecin],dmin[nod]+cost)){

                    nrd[vecin]=((nrd[nod]%104659)+(nrd[vecin]%104659))%104659;

                }

            }

        }

    }

}



void read(){

    freopen("dmin.in","r",stdin);

    scanf("%d%d",&n,&m);

    for (int i=1;i<=m;i++){

        int x,y,c;

        scanf("%d%d%d",&x,&y,&c);

        double nc=log(c);

        G[x].push_back(make_pair(y,nc));

        G[y].push_back(make_pair(x,nc));

    }

}



int egal(double x,double y){

    return abs(x-y)<1e-9;

}
