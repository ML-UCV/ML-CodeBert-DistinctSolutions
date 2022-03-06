#include <cstdio>
#include <cmath>
#include <algorithm>


using namespace std;



const long long inf=1e18;

struct punct

{

    int x,y;

    bool operator <(const punct &aux) const

    {

        if(x==aux.x) return y<aux.y;

        return x<aux.x;

    }

}v[100010],aux[100010];



int cmp(punct &a,punct &b)

{

    if(a.y==b.y) return a.x<b.x;

    return a.y<b.y;

}



long long sqr(int a)

{

    return 1LL*a*a;

}



long long dist(punct &a,punct &b)

{

    return sqr(a.x-b.x)+sqr(a.y-b.y);

}



long long solve(int st,int dr)

{

    if(st>=dr) return inf;

    else if(st+1==dr)

    {

        if(cmp(v[dr],v[st])) swap(v[st],v[dr]);

        return dist(v[st],v[dr]);

    }

    int mid=(st+dr)/2,midx=v[mid].x;

    long long d=min(solve(st,mid),solve(mid+1,dr));

    merge(v+st,v+mid+1,v+mid+1,v+dr+1,aux,cmp);

    for(int i=st;i<=dr;i++) v[i]=aux[i-st];

    int nr=0;

    for(int i=st;i<=dr;i++)

        if(sqr(midx-v[i].x)<=d) aux[++nr]=v[i];

    for(int i=1;i<=nr;i++)

        for(int j=i+1;j<=nr && sqr(aux[j].y-aux[i].y)<=d;j++) d=min(d,dist(aux[i],aux[j]));

    return d;

}



int main()

{

    freopen("cmap.in", "r", stdin);

    freopen("cmap.out", "w", stdout);

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++) scanf("%d%d",&v[i].x,&v[i].y);

    sort(v+1,v+1+n);

    printf("%.8f",sqrt(solve(1,n)));

    return 0;

}
