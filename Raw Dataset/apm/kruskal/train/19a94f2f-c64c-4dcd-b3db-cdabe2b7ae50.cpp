#include<fstream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

set<pair<int,pair<int,int>>>S;

vector<pair<int,int>>G;

int n,m,t,T[100001];

int Radacina(int x)

{

    if(T[x]==x)return x;

    return T[x]=Radacina(T[x]);

}

void Citire()

{

    fin>>n>>m;

    for(int i=1;i<=m;++i)

    {

        int x,y,w;

        fin>>x>>y>>w;

        S.insert({w,{x,y}});

    }

}

void Kruskal()

{

    for(int i=1;i<=n;i++)

        T[i]=i;

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

}

void Afisare()

{

    fout<<t<<'\n';

    fout<<G.size()<<'\n';

    for(auto p : G)

        fout<<p.first<<" "<<p.second<<'\n';

}

int main()

{

    Citire();

    Kruskal();

    Afisare();

    return 0;

}
