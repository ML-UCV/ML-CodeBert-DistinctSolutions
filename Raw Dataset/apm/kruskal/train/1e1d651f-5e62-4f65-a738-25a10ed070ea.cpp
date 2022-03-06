#include <bits/stdc++.h>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

struct muchie{

int x,y,cost;};

struct soll{

int x,y;};

vector<soll>sol;

int h[200100],tata[200100];

void Union(int x,int y);

int Find(int x);

void kruskal();

int costmin,nrsel,n,m;

inline bool operator<(muchie a,muchie b)

{

    return a.cost>b.cost;

}

priority_queue<muchie>heap;

int main()

{

    int i,x,y,z;

   fin>>n>>m;

   for(i=1;i<=m;i++)

   {

       fin>>x>>y>>z;

       heap.push({x,y,z});

   }

   kruskal();

   fout<<costmin<<'\n';

   fout<<sol.size()<<'\n';

   for(i=0;i<sol.size();i++)

    fout<<sol[i].x<<' '<<sol[i].y<<'\n';

}

int Find(int x)

{

    int rad,y;

    rad=x;

    while(tata[rad])

        rad=tata[rad];

    while(tata[x])

    {

        y=tata[x];

        tata[x]=rad;

        x=y;

    }

    return rad;

}

void Union(int x,int y)

{

    if(h[x]>h[y])

        tata[y]=x;

    else{

        tata[x]=y;

        if(h[x]==h[y])

            h[y]++;

    }

}

void kruskal()

{

    muchie a;

    int nrsel=0,rx,ry;

    while(nrsel<n-1)

    {

        a=heap.top();

        heap.pop();

        rx=Find(a.x);

        ry=Find(a.y);

        if(rx!=ry)

        {

            costmin+=a.cost;

            sol.push_back({a.x,a.y});

            nrsel++;

            Union(rx,ry);

        }

    }

}
