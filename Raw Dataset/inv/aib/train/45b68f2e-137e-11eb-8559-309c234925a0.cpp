#include <bits/stdc++.h>


using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

struct xd

{

    long long x,poz;

}a[100009];

long long n,i,v[100009],aib[100009],s;

long long compare (xd a,xd b)

{

    if(a.x!=b.x)

        return a.x<b.x;

    return a.poz<b.poz;

}

void update(long long i,long long x)

{

    for (long long j=i;j<=n;j+=j^(j&(j-1)))

        aib[j]+=x;

}

long long query(long long i)

{

    long long s=0;

    for(long long j=i;j>=1;j-=j^(j&(j-1)))

        s+=aib[j];

    return s;

}

int main()

{

    fin.sync_with_stdio(false);

    fin>>n;

    for(i=1;i<=n;i++)

        fin>>v[i],a[i].x=v[i],a[i].poz=i;

    sort(a+1,a+n+1,compare);

    for(i=1;i<=n;i++)

        v[a[i].poz]=i;

    s=n*(n-1)/2;

    for(i=1;i<=n;i++)

    {

        s-=1LL*query(v[i]);

        update(v[i],1);

    }

    fout<<s%9917;

    return 0;

}
