#include<bits/stdc++.h>
using namespace std;



struct cell

{

    int nod,vecin;

    long double val;

    bool operator <(const cell& e) const

        {

            return val>e.val;

        }

};



ifstream fin("dmin.in");

ofstream fout("dmin.out");



const long double eps=0.000001;

const int MODULO=104659;

const int NMAX=1505;



int n,m,dp[NMAX];

long double cost[NMAX];

vector<cell>v[NMAX];

vector<cell>::iterator it;

priority_queue<cell>Q;



inline void DIJKSTRA()

{

    int i;

    long double aux;

    cell k,kk;

    for (i=1;i<=n;i++) cost[i]=1<<30;

    dp[1]=1;cost[1]=0;

    k.nod=1;k.val=0;

    Q.push(k);

    while (!Q.empty())

        {

            k=Q.top();

            Q.pop();

            for (it=v[k.nod].begin();it!=v[k.nod].end();it++)

                {

                    aux=(k.val+(*it).val);

                    if (fabs(cost[(*it).vecin]-aux)<eps)

                        dp[(*it).vecin]=(dp[(*it).vecin]+dp[k.nod])%MODULO;

                    if (cost[(*it).vecin]>aux+eps)

                        {

                            cost[(*it).vecin]=aux;

                            dp[(*it).vecin]=dp[k.nod];

                            kk.nod=(*it).vecin;

                            kk.val=cost[(*it).vecin];

                            Q.push(kk);

                        }

                }

        }

}



int main()

{

    int i,x,y;

    long double w,c;

    cell k;

    fin>>n>>m;

    for (i=1;i<=m;i++)

        {

            fin>>x>>y>>c;

            w=log(c);

            k.nod=x;k.vecin=y;k.val=w;

            v[x].push_back(k);

            swap(k.nod,k.vecin);

            v[y].push_back(k);

        }

    DIJKSTRA();

    for (i=2;i<=n;i++) fout<<dp[i]<<" ";

    return 0;

}
