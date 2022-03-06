#include <cstdio>
#include <algorithm>
using namespace std;
struct muchie
{
    int x,y,c;
};
int n,m,i,t[200001],h[200001],k,cost,sol[200000];
muchie a[400001];
int compare(muchie x,muchie y)
{
    return x.c<y.c;
}
int muchie(int x,int y)
{
    int r1,r2,x1,y1,c;
    r1=x;
    r2=y;
    while (r1!=t[r1]) r1=t[r1];
    while (r2!=t[r2]) r2=t[r2];
    while (t[x]!=r1)
    {
        x1=t[x];
        t[x]=t[x1];
        x=x1;
    }
    while (t[y]!=r2)
    {
        y1=t[y];
        t[y]=t[y1];
        y=y1;
    }
    if (r1==r2) return 0;
    if (h[r1]>h[r2])
    {
        t[r2]=r1;
        c=r1;
    }
    else
    {
        t[r1]=r2;
        c=r2;
    }
    if (h[r1]==h[r2]) h[c]++;
    return 1;
}
int main()
{
    FILE *f1 = fopen("apm.in","r");
    FILE *f2 = fopen("apm.out","w");
    fscanf(f1,"%d%d",&n,&m);
    for (i=1; i<=m; i++)
    {
        fscanf(f1,"%d%d%d",&a[i].x,&a[i].y,&a[i].c);
    }
    sort(a+1,a+m+1,compare);
    for (i=1; i<=n; i++)
    {
        t[i]=i;
        h[i]=1;
    }
    k=0;
    i=1;
    while (k<n-1)
    {
        if (muchie(a[i].x,a[i].y))
        {
            cost+=a[i].c;
            sol[++k]=i;
        }
        i++;
    }
    fprintf(f2,"%d\n%d\n",cost,n-1);
    for (i=1; i<=n-1; i++) fprintf(f2,"%d %d\n",a[sol[i]].x,a[sol[i]].y);
    fclose(f1);
    fclose(f2);
    return 0;

}
