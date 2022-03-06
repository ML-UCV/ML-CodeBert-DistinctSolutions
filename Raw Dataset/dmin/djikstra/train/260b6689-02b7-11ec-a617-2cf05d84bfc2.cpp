#include <cstdio>
#include <set>
#include <cmath>




using namespace std;
const int INF = (1<<30)-5;
const double eps = 1e-10;
struct nod
{
    int x;
 double cost;
    nod *next;
};
nod *G[50005];

int n, m, uz[50005], v[50005];
double d[50005];
 set< pair<double, int> > S;

inline double mabs(double x)
{
 return x<0?-x:x;
}


void addMuchie(int i, int j, int cost)
{
    nod *p = new nod;
    p->x = j;
    p->cost = log(cost);
    p->next = G[i];
    G[i] = p;

}

int minimul()
{
 int min = INF, ibun = -1;
 for (int i = 1; i <= n; ++i)
  if (!v[i] && d[i] < min)
   min = d[i], ibun = i;

 return ibun;
}

void dijkstra()
{



   v[1] = 1;
   int i;


   for (nod *p = G[1]; p; p = p -> next)
  d[p->x]=(double)p->cost, uz[p->x]=1;
 d[1] = 0.0;
 uz[1] = 1;
   for (int k = 1; k < n; ++k)
   {

      i = minimul();
 if (i == -1) break;
      v[i] = 1;

      for (nod *p = G[i]; p; p = p -> next)
       if (!v[p->x])
       {
  if (d[p->x] > d[i] + p->cost + eps)
                    d[p->x] = d[i] + p->cost,uz[p->x] = uz[i];
    else
            if (mabs(d[p->x] - (d[i] + p->cost)) <= eps)
     uz[p->x] = (uz[i] + uz[p->x]) % 104659, uz[p->x] %= 104659;
            else;

       }

   }

}

int main()
{
    FILE *f = fopen("dmin.in", "r");
    fscanf(f, "%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        d[i] = INF, uz[i] = 0;
 for (int x, y, c; m; --m)
    {
        fscanf(f, "%d%d%d", &x, &y, &c);
        addMuchie(x, y, c);
  addMuchie(y, x, c);

    }
    fclose(f);

    dijkstra();
    f = fopen("dmin.out", "w");

    for (int i = 2; i <= n; ++i)
        fprintf(f, "%d ", uz[i]);

    fclose(f);

    return 0;
}
