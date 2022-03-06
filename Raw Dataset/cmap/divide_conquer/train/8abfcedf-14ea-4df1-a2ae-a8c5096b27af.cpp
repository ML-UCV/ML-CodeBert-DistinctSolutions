#include <cstdio>
#include <cmath>
#include <assert.h>
#include <algorithm>

const int Q = 100006;

int n;

struct point{
 int x, y;

 void operator=(const point &alt)
 {
  x = alt.x;
  y = alt.y;
 }

};

point v[Q];

long long dist(const point &a, const point &b)
{
 return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

void swap(point &a, point &b)
{
 point aux;
 aux = a;
 a = b;
 b = aux;
}

int modul(int x)
{
 return x > 0 ? x : -x;
}

bool cmp(const point &a, const point &b)
{
 return a.y < b.y;
}


long long divide_et_impera(int st, int dr, int min, int max)
{

 if(dr - st <= 5 || min == max)
 {
  long long rez = 1e16;
  for(int t1 = st; t1 < dr; t1++)
  {
   for(int t2 = t1 + 1; t2 <= dr; t2++)
   {
    long long act = dist(v[t1], v[t2]);
    if(act < rez)
     rez = act;
   }
  }

  if(st <= dr)
  {
   std::sort(v + st, v + dr + 1, cmp);
  }

  return rez;
 }

 int mid_val = (min + max) / 2;

 int lower_bound = st - 1;

 for(int i = st; i <= dr; i++)
 {
  if(v[i].x <= mid_val)
  {
   swap(v[i], v[++lower_bound]);
  }
 }

 long long rez1, rez2;

 rez1 = divide_et_impera(st, lower_bound, min, mid_val);
 rez2 = divide_et_impera(lower_bound + 1, dr, mid_val + 1, max);

 long long rez;

 if(rez1 < rez2)
  rez = rez1;
 else
  rez = rez2;

 int p1 = st, p2 = lower_bound + 1;

 point *aux;


 aux = new point[dr - st + 1];

 int cnt = 0;


 while(p1 <= lower_bound && p2 <= dr)
 {
  if(v[p1].y < v[p2].y)
  {
   aux[cnt++] = v[p1++];
  }
  else
  {
   aux[cnt++] = v[p2++];
  }
 }

 while(p1 <= lower_bound)
 {
  aux[cnt++] = v[p1++];
 }

 while(p2 <= dr)
 {
  aux[cnt++] = v[p2++];
 }

 for(int i = st; i <= dr; i++)
 {
  v[i] = aux[i - st];
 }

 point *saved;
 saved = new point[dr - st + 1];
 int cs = 0;

 for(int i = st; i <= dr ;i++)
 {

  if(modul(v[i].x - mid_val) <= rez)
  {
   saved[cs++] = v[i];
  }
 }

 for(int p = st; p <= dr; p++)
 {
  for(int oth = p + 1; oth <= p + 7; oth++)
  {
   if(oth > n)
    break;

   long long d = dist(v[p], v[oth]);

   if(d < rez)
    rez = d;
  }
 }

 delete aux;
 delete saved;

 return rez;

}


int main()
{
 freopen("cmap.in", "r", stdin);
 freopen("cmap.out", "w", stdout);

 scanf("%d\n", &n);

 for(int i = 1; i <= n ; i++)
 {
  scanf("%d %d\n", &v[i].x, &v[i].y);
 }

 int lim = 1000000000;

 long long rez = 0;


 rez = divide_et_impera(1, n, -lim, lim);

 double fin = sqrt(rez);


 printf("%.8lf\n", fin);

 return 0;
}
