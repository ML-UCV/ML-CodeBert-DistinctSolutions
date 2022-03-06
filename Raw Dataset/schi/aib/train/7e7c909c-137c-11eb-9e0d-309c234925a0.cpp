#include <bits/stdc++.h>


using namespace std;

ifstream f("schi.in");

ofstream g("schi.out");

int aib[30005],a[30005],sol[30005];

int n,bitMax;

void add(int k,int val)

{

    for(;k<=n;k+=(k&-k))

        aib[k]+=val;

}

void read()

{

    f>>n;

    for(int i=1;i<=n;i++)

    {

        f>>a[i];

        add(i,1);

    }

}

int sum(int val)

{

    int sol=0;

    for(;val>0;val-=(val&-val))

        sol+=aib[val];

    return sol;

}

int query(int val)

{

    int st=1,dr=n,sol,mij,x;

    while(st<=dr)

    {

        mij=(st+dr)/2;

        x=sum(mij);

        if(x>=val)

        {

            dr=mij-1;

            sol=mij;

        }

        else

            st=mij+1;

    }

    return sol;

}

void solve()

{

    for(int i=n;i>=1;i--)

    {

        int pos=query(a[i]);

        sol[pos]=i;

        add(pos,-1);

    }

    for(int i=1;i<=n;i++)

        g<<sol[i]<<"\n";

}

int main()

{

    read();

    solve();

    return 0;

}
