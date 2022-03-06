#include <bits/stdc++.h>


using namespace std;



ifstream in("inv.in");

ofstream out("inv.out");



const int NMAX=1e5, M=9917;



int a[NMAX],N;



int v_merge(int a[],int l, int r, int m)

{

    int i=l;

    int j=m+1;

    int p=l;

    int c[NMAX];

    int ans=0;

    while(i<=m && j<=r)

    {

        if(a[i]<=a[j])

        {

            c[p++]=a[i++];

        }

        else

        {

            c[p++]=a[j++];

            ans+=m-i+1;

            ans%=M;

        }

    }

    for(i;i<=m;++i)

    {

        c[p++]=a[i];

    }

    for(j;j<=r;++j)

    {

        c[p++]=a[j];

    }

    for(int i=l;i<p;++i)

    {

        a[i]=c[i];

    }

    return ans;

}



int ninv(int a[], int l, int r)

{

    if(l>=r)

    {

        return 0;

    }

    {

        int m=(l+r)/2;

        int ileft=ninv(a,l,m);

        int iright=ninv(a,m+1,r);

        return (ileft+iright+v_merge(a,l,r,m))%M;

    }

}



void read()

{

    in>>N;

    for(int i=0;i<N;++i)

    {

        in>>a[i];

    }

}



void solve()

{

    read();

    int ans=ninv(a,0,N-1);

    out<<ans;

}



int main()

{

    read();

    solve();

    return 0;

}
