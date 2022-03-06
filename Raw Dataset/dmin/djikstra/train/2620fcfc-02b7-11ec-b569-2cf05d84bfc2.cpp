# include <fstream>
# include <iostream>
# include <cmath>


using namespace std;
struct nod {
 int capat;
 double cost;
 nod *next;};
int n, nrd[15003], v[15003];
double d[15003];
nod *g[15003];

void add (int i, int j, int c)
{
 nod *p=new nod;
 p->capat=j;
 p->cost=log10((double)c);
 p->next=g[i];
 g[i]=p;
}

void read ()
{
 ifstream fin ("dmin.in");
 int m;
 fin>>n>>m;
 for (int i=1;i<=n;i++)
  d[i]=1000000000;
 int i, j, c;
 for (;m;--m)
 {
  fin>>i>>j>>c;
  add(i, j, c);
  add(j, i, c);
 }
}

int min ()
{
 int i=1, m;
 while (v[i])++i;
 m=i;
 for (++i;i<=n;i++)
  if (v[i]==0 && d[i]<d[m])
   m=i;
 return m;
}

void dijkstra ()
{
 int dmin;
 d[1]=0;
 nrd[1]=1;
 for (int i=1;i<n;i++)
 {
  dmin=min();
  v[dmin]=1;
  for (nod *p=g[dmin];p;p=p->next)
   if(d[p->capat]>d[dmin]+p->cost+0.0000000001)
   {
    d[p->capat]=d[dmin]+p->cost;
    nrd[p->capat]=nrd[dmin];
   }
   else
    if (p->cost+d[dmin]-d[p->capat]<0.0000000001 && p->cost+d[dmin]-d[p->capat]>-0.0000000001)
     nrd[p->capat]=(nrd[dmin]+nrd[p->capat]) % 104659;
 }
}

void afis ()
{
 ofstream fout ("dmin.out");
 for (int i=2;i<=n;i++)
  fout<<nrd[i]<<" ";
}

int main ()
{
 read ();
 dijkstra ();
 afis ();
 return 0;
}
