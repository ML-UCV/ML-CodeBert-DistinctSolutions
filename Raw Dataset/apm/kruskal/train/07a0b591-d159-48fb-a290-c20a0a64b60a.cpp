#include <bits/stdc++.h>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

int tata[200009];

int h[200009];

struct tip{int x; int y;int c;};

vector <tip> v;

long long int n,m,cost;

vector<int> sol;

void citire();

bool compar( tip a, tip b)

{

    return a.c<b.c;

}

int afla(int x)

{int cop=x;

  while(tata[x])

        x=tata[x];

  while(tata[cop])

        {

          int ret=cop;

          cop=tata[cop];

          tata[ret]=x;

        }

 return x;

}

void unire(int x, int y)

{

  if(h[x]>h[y])

        {tata[y]=x;return;}

  tata[x]=y;

  if(h[x]==h[y])

       h[y]++;

}



void afis();

int main()

{citire();

 afis();

    return 0;

}

void citire()

{int x,y,c,i;

    fin>>n>>m;

    for(i=1;i<=m;i++)

        {

         fin>>x>>y>>c;

         v.push_back({x,y,c});



        }

  sort(v.begin(),v.end(),compar);

int nrsel=0;

for(i=0;i<v.size() && nrsel!=n-1;i++)

    {

     int x=v[i].x;



     int y=v[i].y;

     int compx, compy;

     compx=afla(x);

     compy=afla(y);

     if(compx!=compy)

        {unire(compx,compy);

        cost+=v[i].c;

        sol.push_back(i);

        nrsel++;

        }

    }

}

void afis()

{

 int i;

 fout<<cost<<"\n"<< n-1<<'\n';

 for(i=0;i< sol.size();i++)

       fout<< v[sol[i]].x<<" "<<v[sol[i]].y<<'\n';



}
