#include <stdio.h> 
#include <limits.h>
#include <math.h> 
#include <vector>
#include <queue>





using namespace std;

typedef pair <double, int> di;

int n, m, np [1515];
vector <di> g [1515];
vector <double> d (1515, (double)INT_MAX);
priority_queue <di, vector <di>, greater <di> > q;

void scan ()
{
 int i, a, b, c;
 double k;
 scanf ("%d%d", &n, &m);
 for (i=1; i <= m; ++i)
 {
  scanf ("%d%d%d", &a, &b, &c);
  k=(double)log10 (c);
  g [a].push_back (di (k, b));
  g [b].push_back (di (k, a));
 }
}

void dijkstra ()
{
 vector <di> :: iterator it;
 int k;
 double da;
 q.push (di (0, 1));
 d [1]=0;
 np [1]=1;
 while (!q.empty ())
 {
  k=q.top ().second;
  da=q.top ().first;
  q.pop ();
  if (da > d [k]) continue;
  for (it=g [k].begin (); it != g [k].end (); ++it)
  {
   if (d [it->second] > d [k] + (it->first))
   {
    d [it->second] = d [k] + (it->first);
    q.push (di (d [it->second], it->second));
   }
  }
 }
}

inline double make_abs (double x)
{
 if (x < 0)
        return -x;
 return x;
}

void nrpos (int k)
{
 vector <di> :: iterator it;
 for (it=g [k].begin (); it != g [k].end (); ++it)
  if (make_abs (d [k] - d [it->second] - (it->first)) < 0.00000001)
  {
   if (np [it->second] == 0)
          nrpos (it->second);
   np [k] += np [it->second];
   np [k] %= 104659;
  }
}

void print ()
{
 for (int i=2; i <= n; ++i)

  printf ("%d ", np [i]);

 printf ("\n");
}

int main ()
{
 freopen ("dmin.in", "r", stdin);
 freopen ("dmin.out", "w", stdout);
 scan ();
 dijkstra ();
 for (int i=2; i <= n; ++i)
  if (np [i] == 0)
   nrpos (i);
 print ();
 return 0;
}
