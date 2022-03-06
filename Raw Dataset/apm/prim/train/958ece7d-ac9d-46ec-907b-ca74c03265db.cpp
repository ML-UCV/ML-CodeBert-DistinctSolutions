#include <bits/stdc++.h>
using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

const int NMAX=200005,INF=0x3F3F3F3F;

int n,m,x,y,price,cost[NMAX];

vector<pair<int,int>>edge[NMAX];

bitset<NMAX>ok;

struct stalker

{

    int a,b;

} solution[NMAX];

void prim(int n)

{

    int mn,node,k=0;

    long long answer=0;

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

    ok[1]=1;

    for(int i=1; i<=n; i++)

        cost[i]=INF;

    for(auto next: edge[1])

    {

        cost[next.first]=next.second;

        pq.push({next.second,{next.first,1}});

    }

    for(int i=1; i<=n-1; i++)

    {

        while(ok[pq.top().second.first]==1)

            pq.pop();

        mn=pq.top().first;

        node=pq.top().second.first;

        answer+=mn;

        solution[++k].a=node;

        solution[k].b=pq.top().second.second;

        ok[node]=1;

        for(auto next:edge[node])

        {

            cost[next.first]=min(cost[next.first],next.second);

            pq.push({next.second,{next.first,node}});

        }

    }

    g<<answer<<"\n"<<n-1<<"\n";

    for(int i=1; i<=k; i++)

        g<<solution[i].a<<" "<<solution[i].b<<"\n";

}

int main()

{

    f>>n>>m;

    for(int i=0; i<=m; i++)

    {

        f>>x>>y>>price;

        edge[x].push_back({y,price});

        edge[y].push_back({x,price});

    }

    prim(n);

    return 0;

}
