#include <bits/stdc++.h>




using namespace std;





ifstream fin ("apm.in");

ofstream fout ("apm.out");

void read();

int n, m, t[200001], ct,viz[200001];

struct pereche

{

    int y,c;

};



struct muchie

{

    int x, y, c;

};



struct cmp

{

    bool operator()(muchie u, muchie v)

    {

        return u.c > v.c;

    }

};





priority_queue<muchie, vector<muchie>, cmp> q;



vector<pereche> G[200001];



void citeste()

{

    int x,y,i,cost;

    fin >> n >> m;

    for(i=1; i<=m; i++)

    {

        pereche p;

        fin >> x >> y >> cost;

        p={y,cost};

        G[x].push_back(p);

        p={x,cost};

        G[y].push_back(p);

    }

}



int main()

{

    int i,nr;

    muchie e;

    pereche p;



    citeste();

    for(i=0;i<G[1].size();i++)

    {

       p=G[1][i];

       q.push({1, p.y, p.c});

       t[p.y]=1;

    }

    viz[1]=1;

    nr=0;

    while(nr<n-1)

    {

        e= q.top();

        q.pop();



        if(viz[e.y]==0)

        {

            nr++;

            viz[e.y]=1;

            t[e.y]=e.x;

            ct=ct+e.c;

            for(i=0;i<G[e.y].size();i++)

            {

              p=G[e.y][i];

                if(viz[p.y]==0)

                    q.push({e.y, p.y,p.c});

            }

        }

    }

    fout << ct << '\n';
    fout<<n-1<<'\n';

    for(i=2;i<=n;i++)

        fout<<i<<' '<<t[i]<<'\n';

    return 0;

}
