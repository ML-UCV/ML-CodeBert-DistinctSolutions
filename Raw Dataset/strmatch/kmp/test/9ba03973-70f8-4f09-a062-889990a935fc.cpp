#include <bits/stdc++.h>


using namespace std;

ifstream in("strmatch.in");

ofstream out("strmatch.out");

char a[2000005],b[2000005];

int n,m,p[2000005],ans[2000005],k;

int main()

{

    in>>(a+1);

    in>>(b+1);

    n=strlen(a+1);

    m=strlen(b+1);

    int i=2,j=0;

    while(i<=n)

    {

        while(a[i]!=a[j+1]&&j>0) j=p[j];

        if(a[i]==a[j+1]) j++;

        p[i]=j;

        i++;

    }

    j=0;

    i=1;

    while(i<=m)

    {

        while(b[i]!=a[j+1]&&j>0) j=p[j];

        if(b[i]==a[j+1]) j++;

        if(j==n)

        {

            ans[++k]=i-n;

            j=p[n];

        }

        i++;

    }

    out<<k<<'\n';

    for(int i=1;i<=min(k,1000);i++) out<<ans[i]<<" ";

    return 0;

}
