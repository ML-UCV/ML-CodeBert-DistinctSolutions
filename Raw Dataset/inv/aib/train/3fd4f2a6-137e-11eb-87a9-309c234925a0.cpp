#include <bits/stdc++.h>
using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

long long i,n,m,a[100005],b[100005],v[100005],aib[100005],st,dr,poz,mij,nr;

int ub(int x)

{

    return(x&(-x));

}

long long sum(int x)

{

    long long s=0;

    for(int i=x; i>=1; i-=ub(i))

    {

        s+=aib[i];

        s%=9917;

    }

    return s;

}

void Add(int x)

{

    for(int i=x; i<=m; i+=ub(i))

    {

        aib[i]++;

        aib[i]%=9917;

    }

}

int main()

{

    f>>n;

    for(i=1; i<=n; ++i)

    {

        f>>a[i];

        b[i]=a[i];

    }

    sort(b+1,b+n+1);

    v[++m]=b[1];

    for(i=2; i<=n; ++i)

        if(b[i]!=b[i-1])

            v[++m]=b[i];

    for(i=1; i<=n; ++i)

    {

        st=1;

        dr=m;

        poz=0;

        while(st<=dr)

        {

            mij=(st+dr)/2;

            if(v[mij]<=a[i])

            {

                poz=mij;

                st=mij+1;

            }

            else

                dr=mij-1;

        }

        a[i]=poz;

    }

    for(i=n; i>=1; --i)

    {

        nr+=sum(a[i]-1);

        nr%=9917;

        Add(a[i]);

    }

    g<<nr<<'\n';

    return 0;



}
