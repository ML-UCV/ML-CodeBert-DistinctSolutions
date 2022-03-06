#include <bits/stdc++.h>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

int urm[2000005],n,k,q,m,sol[1005],i,p;

char N[2000005],M[2000005];

int main()

{

    f>>N;

    n=strlen(N);

    for(i=2;i<=n;i++)

    {

        while(k>0&&N[k]!=N[i-1]) k=urm[k];

        if(N[k]==N[i-1]) k++;

        urm[i]=k;

    }

    f>>M;

    m=strlen(M);

    for(i=0;i<m;i++)

    {

        while(q>0&&N[q]!=M[i]) q=urm[q];

        if(N[q]==M[i]) q++;

        if(q==n)

        {

            p++;

            if(p<=1000)

            {

                sol[p]=i;

            }

        }

    }

    g<<p<<'\n';

    for(i=1;i<=min(p,1000);i++) g<<sol[i]-n+1<<" ";

    return 0;

}
