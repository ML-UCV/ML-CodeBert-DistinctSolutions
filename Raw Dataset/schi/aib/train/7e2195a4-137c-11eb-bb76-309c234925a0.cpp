#include <bits/stdc++.h>
using namespace std;

int n,fin[30005],a[30005],aib[30005];

ifstream in("schi.in");

ofstream out("schi.out");

void update(int p,int x)

{

    for (;p<=n;p+=(p&(-p)))

        aib[p]+=x;

}

int query(int p)

{

    int s=0;

    for (;p>0;p-=(p&(-p)))

        s+=aib[p];



    return s;

}

int cautbin(int x)

{

    int st=1,dr=n,fin=0,mij;

    while (st<=dr)

    {

        mij=(st+dr)/2;

        if (query(mij)<x)st=mij+1;

        else

        {

            fin=mij;

            dr=mij-1;

        }

    }

    return fin;

}

int main()

{

    in>>n;

    int i,poz;

    for (i=1;i<=n;i++)in>>a[i];

    for (i=1;i<=n;i++)update(i,1);

    for (i=n;i>=1;i--)

    {

        poz=cautbin(a[i]);

        update(poz,-1);

        fin[poz]=i;

    }

    for (i=1;i<=n;i++)out<<fin[i]<<"\n";

    out.close();

    in.close();

    return 0;

}
