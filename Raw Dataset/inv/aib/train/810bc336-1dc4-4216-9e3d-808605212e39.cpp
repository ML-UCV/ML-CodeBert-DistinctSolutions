#include <bits/stdc++.h>


using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

const int N=200009;

struct xd

{

    long long x;

    int poz;

}a[N];

int n;

int aib[N],v[N];

int compare(xd a,xd b)

{

    if(a.x!=b.x)

        return a.x<b.x;

    return a.poz<b.poz;

}

void update(int x,int y)

{

    while(x<=n)

    {

        aib[x]+=y;

        x+=x&(-x);

    }

}

int query(int x)

{

    int sum=0;

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

    for(int i=1;i<=n;i++)

        fin>>a[i].x,a[i].poz=i;

}

void solve()

{

    sort(a+1,a+n+1,compare);

    for(int i=1;i<=n;i++)

        v[a[i].poz]=i;

    int s=0;

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
