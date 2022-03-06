#include <bits/stdc++.h>


using namespace std;



const long long inf=1e18;



struct pct

{

    int x,y;

}v[100010],v1[100010];



int cmp(pct a,pct b)

{

    return a.x<b.x;

}



int cmp1(pct a,pct b)

{

    return a.y<b.y;

}



long long p2(int x)

{

    return 1LL*x*x;

}



long long dist(pct a,pct b)

{

    return p2(a.x-b.x)+p2(a.y-b.y);

}



long long solve(int st,int dr)

{

    if(st>=dr) return inf;

    if(st+1==dr)

    {

        if(v[dr].y<v[st].y) swap(v[st],v[dr]);

        return dist(v[st],v[dr]);

    }

    int mid=(st+dr)/2,mval=v[mid].x;

    long long ans=min(solve(st,mid),solve(mid+1,dr));

    merge(v+st,v+mid+1,v+mid+1,v+dr+1,v1+st,cmp1);

    int nr=0;

    for(int i=st;i<=dr;i++)

    {

        v[i]=v1[i];

        if(p2(v1[i].x-mval)<=ans) v1[++nr]=v1[i];

    }

    for(int i=1;i<=nr;i++)

        for(int j=i+1;j<=nr && p2(v1[i].y-v1[j].y)<=ans;j++)

            ans=min(ans,dist(v1[i],v1[j]));

    return ans;

}



int main()

{

    freopen("cmap.in","r",stdin);

    freopen("cmap.out","w",stdout);

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++) scanf("%d%d",&v[i].x,&v[i].y);

    sort(v+1,v+n+1,cmp);

    printf("%.10f",sqrt(solve(1,n)));

    return 0;

}
