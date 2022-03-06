#include <bits/stdc++.h>
using namespace std;



ifstream fin ("dmin.in");

ofstream fout ("dmin.out");



const int nmax=1505;

const int mod=104659;

const long double inf=1e8;

const long double eps=1e-10;



typedef pair< long double, int > pdi;

typedef pair< int,long double > pid;

priority_queue <pdi, vector<pdi>, greater<pdi> > Q;

vector<pid> G[nmax];

long double d[nmax];

int n,m,sol[nmax];

bitset <nmax> bit;



long double ab(long double x){

    return (x>=0?x:-x);

}



void dijkstra(){

    sol[1]=1;

    for(int i=2;i<=n;++i)d[i]=inf;

    d[1]=0;

    Q.push({0,1});

    while(!Q.empty()){

        int node=Q.top().second;

        long double nnnn=Q.top().first;

        Q.pop();

        if(nnnn>d[node])continue;

        for(auto edge: G[node]){

            int nod=edge.first;

            long double dist=edge.second;

            if((d[nod]-d[node]-dist)>eps){

                d[nod]=d[node]+dist;

                Q.push({d[nod],nod});

                sol[nod]=sol[node];

            }

            else if(ab(d[nod]-d[node]-dist)<eps)

                sol[nod]=(sol[nod]+sol[node])%mod;

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

    dijkstra();

    for(int i=2;i<=n;++i)fout<<sol[i]<<' ';

    fout<<'\n';

    return 0;

}
