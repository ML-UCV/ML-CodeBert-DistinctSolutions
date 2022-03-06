#include <bits/stdc++.h>


using namespace std;

ifstream fin ("apm.in");

ofstream fout("apm.out");

struct muchie

{

    int x,y,c;

};

struct pereche

{

    int y,c;

};

struct comp

{

    bool operator()(muchie u, muchie v)

    {

        if(u.c>v.c)

            return 1;

        return 0;

    }

};

vector<pereche>G[200001];

priority_queue<muchie,vector<muchie>,comp>q;

int n,m,x,y,c,t[200001],nr, viz[200001],ct;

int main()

{

    pereche p;

    int i;

    fin>>n>>m;

    for(i=1;i<=m;i++)

    {

        fin>>x>>y>>c;

        p={y,c};

        G[x].push_back(p);

        p={x,c};

        G[y].push_back(p);

    }

    for(i=0;i<G[1].size();i++)

    {

        p=G[1][i];

        q.push({1,p.y,p.c});

        t[p.y]=1;

    }

     viz[1]=1;



    while(nr<n-1)

          {

              muchie e;

              e=q.top();

              q.pop();



              if(viz[e.y]==0)

                {

                    nr++;

                    ct=ct+e.c;

                    viz[e.y]=1;

                    t[e.y]=e.x;

                    for(i=0;i<G[e.y].size();i++)

                    {

                        p=G[e.y][i];

                        if(viz[p.y]==0)

                           q.push({e.y,p.y,p.c});

                    }

                }

          }

          fout<<ct<<'\n';

          fout<<n-1<<'\n';

          for(i=2;i<=n;i++)

            fout<<i<<' '<<t[i]<<'\n';

    return 0;

}
