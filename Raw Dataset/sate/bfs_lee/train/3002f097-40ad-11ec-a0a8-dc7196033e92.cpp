#include <stdio.h>
#include <stdlib.h>
#define infile "sate.in"
#define outfile "sate.out"
#define nmax 30001 
#define mmax 100025
 
int n, X, Y, a[2*mmax];
int m, i, dist[nmax];
int *g[nmax], b[2*mmax], q[2*mmax];
 
 
void readdata();
void writedata();
void solve();
 
int main()
{
 readdata();
 solve();
 writedata();
 return 0;
}
 
void readdata()
{
 int x, y;
 long z;
 freopen(infile, "r", stdin);
 scanf("%d %ld %d %d\n", &n, &m, &X, &Y);
 for (i=1; i<=n; i++)
      g[i]=(int *)calloc(1,sizeof(int));
 for (i=1; i<=m; i++)
     {
      scanf("%d %d %ld\n", &x, &y, &z);
      g[x]=(int *)realloc(g[x], (g[x][0]+2)*sizeof(int));
      g[y]=(int *)realloc(g[y], (g[y][0]+2)*sizeof(int));
      g[x][++g[x][0]]=2*i-1;
      g[y][++g[y][0]]=2*i;
      a[2*i-1]=y;
      b[2*i-1]=z;
      a[2*i]=x;
      b[2*i]=z;
     }
 fclose(stdin);
}
 
void writedata()
{
 freopen(outfile, "w", stdout);
 printf("%d\n", dist[Y]);
 fclose(stdout);
}
 
void solve()
{
 int x;
 int p, u;
 q[1]=X;
 p=u=1;
 while (p<=u)
     {
      x=q[p++];
      for (i=1; i<=g[x][0]; i++)
      if (!dist[a[g[x][i]]])
      {
       if (x<a[g[x][i]])
           dist[a[g[x][i]]]=dist[x]+b[g[x][i]];
       else
           dist[a[g[x][i]]]=dist[x]-b[g[x][i]];
       if (dist[Y]) return;
       q[++u]=a[g[x][i]];
      }
     }
}
