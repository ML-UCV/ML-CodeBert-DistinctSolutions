#include <bits/stdc++.h>
using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");

int n,a[30002],loc[30002],fin[30002];

void update(int i)

{

    while(i<=n)

    {

        a[i]++;

        i+=(i&(-i));

    }

}

int q(int i)

{

    int s=0;

    while(i)

    {

        s+=a[i];

        i-=(i&(-i));

    }

    return s;

}

int main()

{

    int i,nr,nrr;

    in>>n;

    for(i=1;i<=n;i++)

        in>>loc[i];

    for(i=n;i>0;i--)

    {

        nr=q(loc[i]);

        if(nr)

        {

            nrr=q(loc[i]+nr);

            while(nr!=nrr)

                nr=nrr,nrr=q(loc[i]+nrr);

        }

        loc[i]+=nr;

        fin[loc[i]]=i;

        update(loc[i]);

    }

    for(i=1;i<=n;i++)

        out<<fin[i]<<"\n";

    return 0;

}
