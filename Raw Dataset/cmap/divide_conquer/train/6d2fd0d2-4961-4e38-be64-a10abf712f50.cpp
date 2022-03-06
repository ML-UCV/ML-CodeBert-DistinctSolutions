#include <bits/stdc++.h>




using namespace std;

ifstream in("cmap.in");
ofstream out("cmap.out");

int n;
pair<long long,long long> pct[100001],cpy[100001];
long long Z;

long long dist(pair<long long,long long> a,pair<long long,long long> b)
{
    return (b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second);
}

void Find(int st,int dr)
{
    if(dr<=st)
        return;

    if(st+1==dr)
    {
        if(pct[st].second>pct[dr].second)
            swap(pct[st],pct[dr]);

        Z=min(Z,dist(pct[st],pct[dr]));

        return;
    }

    int mid=(st+dr)/2;

    Find(st,mid);Find(mid+1,dr);

    int p1=st,p2=mid+1;
    int poz=st;

    while(p1<=mid && p2<=dr)
        if(pct[p1].second<=pct[p2].second)
            cpy[poz++]=pct[p1++];
        else
            cpy[poz++]=pct[p2++];

    while(p1<=mid)
        cpy[poz++]=pct[p1++];

    while(p2<=dr)
        cpy[poz++]=pct[p2++];

    for(int i=st;i<=dr;i++)
        pct[i]=cpy[i];

    for(int i=st;i<=dr;i++)
        for(int j=i+1;j<=min(i+8,dr);j++)
            Z=min(Z,dist(pct[i],pct[j]));
}

int main()
{
    in>>n;

    for(int i=1;i<=n;i++)
        in>>pct[i].first>>pct[i].second;

    sort(pct+1,pct+1+n);

    Z=dist(pct[1],pct[2]);

    Find(1,n);

    out<<setprecision(6)<<fixed<<sqrt(Z);

    return 0;
}
