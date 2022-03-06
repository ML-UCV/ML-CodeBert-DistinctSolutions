#include<iostream>
#include<fstream>
#include<vector>
#include<set>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

set<pair<int,pair<int,int>>>S;

vector<pair<int,int>>G;

int T[200005];

int n,m,t;

void Citire()

{

    fin>>n>>m;

    for(int i=1;i<=n;i++)

        T[i]=i;

    for(int i=1;i<=m;i++)

    {

        int x,y,w;

        fin>>x>>y>>w;

        S.insert({w,{x,y}});

    }

}

int Radacina(int x)

{

    if(T[x]==x)return x;

    return T[x]=Radacina(T[x]);

}

int main()

{

    Citire();

    for(auto p : S)

    {

        int w=p.first;

        auto p2=p.second;

        int x=p2.first;

        int y=p2.second;

        int rx=Radacina(x);

        int ry=Radacina(y);

        if(rx!=ry)

        {

            T[ry]=rx;

            t=t+w;

            G.push_back({x,y});

        }

    }

    fout<<t<<'\n'<<G.size()<<'\n';

    for(auto p : G)

        fout<<p.first<<" "<<p.second<<'\n';

    return 0;

}
