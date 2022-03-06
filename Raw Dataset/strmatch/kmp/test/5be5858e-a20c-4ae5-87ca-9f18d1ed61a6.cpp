#include <bits/stdc++.h>


using namespace std;







ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int NMAX=2000005;

char a[NMAX],b[NMAX];

int p[NMAX],poz[1024],k,n,m;



int main()

{



    fin >> a >> b;

    n=strlen(a); m=strlen(b);



    for(int i=n;i;i--)

        a[i]=a[i-1];

    int q=0;

    for(int i=2;i<=n;i++)

    {

        while(q and a[q+1]!=a[i])

            q=p[q];

        if(a[i]==a[q+1])

            q++;

        p[i]=q;

    }

    q=0;

    for(int i=0;i<m;i++)

    {

        while(q and a[q+1]!=b[i])

            q=p[q];

        if(b[i]==a[q+1])

            q++;

        if(q==n)

        {

            q=p[n];

            k++;

            if(k<=1000)

                poz[k]=i-n+1;

        }

    }

    fout << k << "\n";

    for(int i=1;i<=min(k,1000);i++)

        fout << poz[i] << " ";



    return 0;



}
