#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

char a[2000010],b[2000010];

int ans[1010],i,n,m,p[2000010],nr;

int main()

{

    f>>(a+1);n=strlen(a+1);

    f>>(b+1);m=strlen(b+1);

    int k=0;

    for(i=2;i<=n;i++)

    {

        while(k!=0&&a[k+1]!=a[i])k=p[k];

        if(a[k+1]==a[i])k++;

        p[i]=k;

    }

    k=0;

    for(i=1;i<=m;i++)

    {

        while(k!=0&&a[k+1]!=b[i])k=p[k];

        if(a[k+1]==b[i])k++;

        if(k==n)

        {

            k=p[k];

            nr++;

            if(nr<=1000)

            {

                ans[nr]=i-n;

            }

        }

    }

    g<<nr<<'\n';

    for(i=1;i<=min(nr,1000);i++)

    {

        g<<ans[i]<<" ";

    }

    return 0;

}
