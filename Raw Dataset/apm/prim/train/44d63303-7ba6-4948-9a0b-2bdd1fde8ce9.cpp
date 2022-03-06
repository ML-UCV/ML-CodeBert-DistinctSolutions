#include <bits/stdc++.h>






using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > >h;

vector<pair<int,int> >v[200003];

vector<pair<int,int> >sol;

int n,m,x,y,c;

bool viz[200003];



int prim(int x)

{

    int i,j,cst=0,ct,nod;

    viz[x]=1;

    for(i=1; i<=n-1; i++)

    {

        for(j=0; j<v[x].size(); j++)

        {

            nod=v[x][j].second;

            ct=v[x][j].first;

            if(!viz[nod]) h.push({ct,{x,nod}});

        }

        while(viz[h.top().second.second]) h.pop();

        cst+=h.top().first;

        viz[h.top().second.second]=1;

        sol.push_back({h.top().second.first,h.top().second.second});

        x=h.top().second.second;

        h.pop();

    }



    return cst;



}

int main()

{

    int i;

    f>>n>>m;

    for(i=1; i<=m; i++)

    {

        f>>x>>y>>c;

        v[x].push_back({c,y});

        v[y].push_back({c,x});

    }

    g<<prim(1)<<'\n'<<n-1<<'\n';

    for(i=0; i<sol.size(); i++)

        g<<sol[i].first<<' '<<sol[i].second<<'\n';

    return 0;

}
