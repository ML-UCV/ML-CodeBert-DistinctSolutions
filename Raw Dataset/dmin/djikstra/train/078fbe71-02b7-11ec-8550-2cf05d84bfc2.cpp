#include <bits/stdc++.h>
using namespace std;



ifstream fin ("dmin.in");

ofstream fout ("dmin.out");



const int nmax=1505;

const int mod=104659;

const long double inf=1e8;

const long double dif=1e-10;



typedef pair< long double, int > pdi;

typedef pair< int,long double > pid;

priority_queue <pdi, vector<pdi>, greater<pdi> > Q;

vector<pid> G[nmax];

long double d[nmax];

int n,m,r[nmax];





void dijkstra(int node){

    for(int i=1;i<=n;++i)d[i]=inf;

    r[node]=1;

    d[node]=0;

    Q.push({0,node});

    while(!Q.empty()){

        long double dist=Q.top().first;

        int node_st=Q.top().second;

        Q.pop();

        if(d[node_st]<dist)continue;

        for(auto edge: G[node_st]){

            if(d[edge.first]-(d[node_st]+edge.second)>=dif){

                d[edge.first]=d[node_st]+edge.second;

                r[edge.first]=r[node_st];

                Q.push({d[edge.first],edge.first});

            }

            else if(abs(d[edge.first]-(d[node_st]+edge.second))<dif)

                r[edge.first]=(r[edge.first]+r[node_st])%mod;

        }

    }

}



int main()

{

    int a,b;

    long double c;

    fin>>n>>m;

    for(int i=1;i<=m;++i){

        fin>>a>>b>>c;

        long double l=log10(c);

        G[a].push_back({b,l});

        G[b].push_back({a,l});

    }

    dijkstra(1);

    for(int i=2;i<=n;++i)fout<<r[i]<<' ';

    fout<<'\n';

    return 0;

}
