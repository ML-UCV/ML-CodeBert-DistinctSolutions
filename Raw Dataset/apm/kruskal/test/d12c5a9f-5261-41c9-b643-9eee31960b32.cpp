#include <bits/stdc++.h>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

struct tip{int x; int y; int c;};

bool operator <(tip a, tip b)

{

  return a.c>b.c;

}

priority_queue<tip>H;

vector<tip>sol;

int n,m;

int tata[200009];

int h[200009];

void citire();

void solve();



int aflare(int x);



void unire(int x, int y);

int main()

{citire();

 solve();

    return 0;

}

void citire()

{ tip val;

  int i;

  fin>>n>>m;

  for(i=1;i<=m;i++)

    {

     fin>>val.x>>val.y>>val.c;

     H.push(val);

    }

}

void solve()

{int cx,cy,i;

 int cost=0;

 int nrsel=0;

 while(nrsel!=n-1 && !H.empty())

    {

     tip act=H.top();H.pop();

     int cx=aflare(act.x);

     int cy=aflare(act.y);

     if(cx!=cy)

        {unire(cx,cy);nrsel++;cost+=act.c;sol.push_back(act);}

    }

  fout<<cost<<'\n';

  fout<<sol.size()<<'\n';

  for(i=0;i<sol.size();i++)

    fout<<sol[i].x<<" "<<sol[i].y<<'\n';

}

int aflare(int x)

{

 int cop,rad;

 cop=x;

 while(tata[x])

    {

     x=tata[x];

    }

  rad=x;

  while(tata[cop])

        {

         x=cop;

         cop=tata[cop];

         tata[x]=rad;

        }

   return rad;

}

void unire(int x, int y)

{

  if(h[x]>h[y])

        tata[y]=x;

  else

  {

    if(h[y]>h[x])

        tata[x]=y;

    else

    {h[y]++;tata[x]=y;}

  }

}
