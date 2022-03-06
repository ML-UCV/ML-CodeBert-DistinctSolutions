#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct nod

{

    long long x,y;

};

int n;

inline bool compare(nod a,nod b)

{

    if(a.x!=b.x)

        return a.x<b.x;

    return a.y<b.y;

}

inline bool comp(nod a,nod b)

{

    if(a.y!=b.y)

        return a.y<b.y;

    return a.x<b.x;

}

nod v[100010],C[100010];

double dist(int s,int d)

{

    if(d-s>3)

    {

        double mn=min(dist(s,(s+d)/2),dist((s+d)/2,d));

        int k=0,ls,ld,i;

        double c=(v[(s+d)/2].x+v[(s+d)/2-1].x)/2;

        i=(s+d)/2-1;

        while(c-v[i].x<=mn && i>=s)

            C[k++]=v[i--];

        i=(s+d)/2;

        while(v[i].x-c<=mn && i<d)

            C[k++]=v[i++];

        sort(C,C+k,comp);

        int j;

        double x;

        for(i=ls;i<k-1;++i)

        for(j=i+1;j<i+8 && j<k;++j)

            mn=min(mn,sqrt(( C[j].x - C[i].x ) * ( C[j].x - C[i].x ) + ( C[j].y - C[i].y ) * ( C[j].y - C[i].y )));

        return mn;

    }

    else

    {

        double mn=1e9;

        int i,j;

        for(i=s;i<d-1;++i)

            for(j=i+1;j<d;++j)

            mn=min(mn,sqrt(( v[i].x - v[j].x ) * ( v[i].x - v[j].x ) + ( v[i].y - v[j].y ) * ( v[i].y - v[j].y ) ) );

        return mn;

    }

}

int main()

{

    freopen("cmap.in","r",stdin);

    freopen("cmap.out","w",stdout);

    int i;

    scanf("%d",&n);

    for(i=0;i<n;++i)

    {

        scanf("%lld%lld",&v[i].x,&v[i].y);

        C[i]=v[i];

    }

    sort(v,v+n,compare);

    double x=(dist(0,n));

    printf("%lf",x);

}
