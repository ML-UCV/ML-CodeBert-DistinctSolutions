#include <bits/stdc++.h>




using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



struct tip{int x; int c;};

struct muc{int x; int y;int c;} mc[400009];

vector<tip> g[200009];

int n,m,cost,tata[200009], h[200009];

vector<int> sol;

bool compar( muc a, muc b)

{

  return a.c<b.c;

}

int Find(int x)

{int aux=x,rad=x;

 while(tata[rad])

      rad=tata[rad];



  while(tata[x])

        {aux=x;

         x=tata[x];

         tata[aux]=rad;

        }

  return rad;

}

void Unite(int x, int y)

{

    if (h[x]>h[y])

        tata[y]=x;

    else

    {if(h[y]>=h[x])

         tata[x]=y;

    if(h[x]==h[y])

        h[y]++;

    }

}

void citire();

void sel();

void afis();

int main()

{



 citire();

 sel();

  afis();

    return 0;

}



void citire()

{

  int i;

  int x,y,c;

  fin>>n>>m;

  for(i=1;i<=m;i++)

  {

    fin>>x>>y>>c;

    g[x].push_back({y,c});

    g[y].push_back({y,c});

    mc[i]={x,y,c};

  }

  sort(mc+1,mc+m+1,compar);

}

void sel()

{

 int nrs=0;

 for(int i=1;i<=m && nrs!=n-1;i++)

    {

     int a=mc[i].x;

     int b=mc[i].y;

     int ca=Find(a),cb=Find(b);

     if(ca!=cb)

        {

         nrs++;

         Unite(ca,cb);

         sol.push_back(i);

         cost+= mc[i].c;

        }

    }

}

void afis()

{

  int i;

  fout<<cost<<'\n';

  fout<<n-1<<"\n";

  for(i=0;i<sol.size();i++)

        fout<<mc[sol[i]].x<<" "<<mc[sol[i]].y<<'\n';

}
