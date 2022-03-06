#include <bits/stdc++.h>

using namespace std;
ifstream f("cmap.in");
ofstream g("cmap.out");
struct punct
{
    double x,y;
};
int n;
punct a[1000005],aux[1000005];
bool cmp(punct p,punct q)
{
    return p.x<q.x;
}
double dist(punct p,punct q)
{
    return (q.x-p.x)*(q.x-p.x)+(q.y-p.y)*(q.y-p.y);
}
double divide(int st,int dr)
{
    if(dr-st<=3)
    {
        double minn=dist(a[st],a[st+1]);
        for(int i=st;i<=dr;i++)
        {
            for(int j=i+1;j<=dr;j++)
            {
                minn=min(minn,dist(a[i],a[j]));
            }
        }
        for(int i=st;i<=dr;i++)
        {
            for(int j=i+1;j<=dr;j++)
            {
                if(a[i].y>a[j].y)
                    swap(a[i],a[j]);
            }
        }
        return minn;
    }
    int k=0;
    int mid=(st+dr)/2;
    int DR=a[mid].x;
    double minn=divide(st,mid);
    minn=min(minn,divide(mid+1,dr));
    int I=st;
    int J=mid+1;
    int nr=0;
    while(I<=mid && J<=dr)
    {
        if(a[I].y<a[J].y)
        {
            k++;
            aux[k]=a[I];
            I++;
        }
        else
        {
            k++;
            aux[k]=a[J];
            J++;
        }
    }
    while(I<=mid)
    {
        k++;
        aux[k]=a[I];
        I++;
    }
    while(J<=dr)
    {
        k++;
        aux[k]=a[J];
        J++;
    }
    for(int i=st;i<=dr;i++)
        a[i]=aux[i-st+1];
    for(int i=st;i<=dr;i++)
    {
        if(abs(a[i].x-DR)<=minn)
        {
            nr++;
            aux[nr]=a[i];
        }
    }
    for(int i=1;i<=nr;i++)
    {
        for(int j=i+1;j<=i+7 && j<=nr;j++)
            minn=min(minn,dist(aux[i],aux[j]));
    }
    return minn;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        f>>a[i].x>>a[i].y;
    sort(a+1,a+n+1,cmp);
    g<<fixed<<setprecision(7)<<sqrt(divide(1,n));
    return 0;
}
