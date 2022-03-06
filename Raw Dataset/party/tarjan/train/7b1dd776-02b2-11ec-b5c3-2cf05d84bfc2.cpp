#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>


using namespace std;

int n, m;

int x[1001], y[1001], tip[1001];
int use[101];


inline bool isOk (int i)
{
 if (tip[i] == 0)
 {
  return (use[x[i]] || use[y[i]]);
 }

 if (tip[i] == 1)
 {
  return (use[x[i]] || !use[y[i]]);

 }

 if (tip[i] == 2)
 {
  return (use[y[i]] || !use[x[i]]);

 }

 if (tip[i] == 3)
 {
  return (!use[x[i]] || !use[y[i]]);
 }


 return false;

}
void solve ()
{
 int ok = 1;

 int i, j;

 for (i = 1; i <= n; ++i)
  use[i] = 1;

 while (ok)
 {
  ok = 0;
  for (i = 1; i <= m; ++i)
   if (isOk (i) == false)
   {
    ok = 1;
    int p = rand () & 1;
    if (p)
     use[x[i]] ^= 1;
    else
     use[y[i]] ^= 1;
   }

 }

 int nr = 0;

 for (i = 1; i <= n; ++i)
  if (use[i])
   ++nr;

 printf ("%d\n", nr);
 for (i = 1; i <= n; ++i)
  if (use[i])
   printf ("%d ", i);
 printf ("\n");


}


int main ()
{
 srand (time (0));

 freopen ("party.in", "r", stdin);
 freopen ("party.out", "w", stdout);

 scanf ("%d %d\n", &n, &m);

 int i;

 for (i = 1; i <= m; ++i)
  scanf ("%d %d %d\n", &x[i], &y[i], &tip[i]);

 solve ();


 return 0;
}
