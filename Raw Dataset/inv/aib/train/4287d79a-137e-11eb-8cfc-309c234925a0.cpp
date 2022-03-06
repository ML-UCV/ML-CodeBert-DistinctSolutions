#include <bits/stdc++.h>


using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

const long long N=200009;

struct xd

{

    long long x,poz;

}a[N];

long long n;

long long aib[N],v[N];

int compare(xd a,xd b)

{

    if(a.x!=b.x)

        return a.x<b.x;

    return a.poz<b.poz;

}

void update(long long x,long long y)

{

    while(x<=n)

    {

        aib[x]+=y;

        x+=x&(-x);

    }

}

long long query(long long x)

{

    long long sum=0;

    while(x)

    {

        sum+=aib[x];

        x-=x&(-x);

    }

    return sum;

}

void read()

{

    fin.sync_with_stdio(false);

    fin>>n;

    for(long long i=1;i<=n;i++)

        fin>>a[i].x,a[i].poz=i;

}

void solve()

{

    sort(a+1,a+n+1,compare);

    for(int i=1;i<=n;i++)

        v[a[i].poz]=i;

    long long s=0;

    for(int i=1;i<=n;i++)

    {

        s+=query(n)-query(v[i]);

        s%=9917;

        update(v[i],1);

    }

    fout<<s%9917;

}

int main()

{

    read();

    solve();

    return 0;

}
