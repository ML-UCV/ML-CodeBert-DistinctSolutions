#include <bits/stdc++.h>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

const int N=30009;

int n;

int v[N],aib[N],a[N];

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

int bin(int st,int dr,int ans)

{

    int sol;

    while(st<=dr)

    {

        int mij=(st+dr)/2;

        int val=query(mij);

        if(val==ans)

            sol=mij;

        if(val>=ans)

            dr=mij-1;

        else

            st=mij+1;

    }

    return sol;

}

void read()

{

    fin.sync_with_stdio(false);

    fin>>n;

    for(int i=1;i<=n; i++)

        fin>>v[i];

}

void solve()

{

    for(int i=1;i<=n;i++)

        update(i,1);

    for(int i=n;i>=1;i--)

    {

        int ans=bin(1,n,v[i]);

        a[ans]=i;

        update(ans,-1);

    }

    for(int i=1;i<=n;i++)

        fout<<a[i]<<'\n';

}

int main()

{

    read();

    solve();

    return 0;

}
