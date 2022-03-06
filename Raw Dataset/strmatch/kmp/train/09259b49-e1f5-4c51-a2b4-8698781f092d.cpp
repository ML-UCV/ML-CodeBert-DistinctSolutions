#include <bits/stdc++.h>


using namespace std;







ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int NMAX=2e6+5;

char a[NMAX],b[NMAX];

int p[NMAX],poz[1005],k,n,m;



int main()

{



    fin >> a >> b;

    n=strlen(a); m=strlen(b);



    int q=0;

    for(int i=1;i<n;i++)

    {

        while(q and a[q]!=a[i])

            q=p[q-1];

        if(a[i]==a[q])

            q++;

        p[i]=q;

    }

    q=0;

    for(int i=0;i<m;i++)

    {

        while(q and a[q]!=b[i])

            q=p[q-1];

        if(b[i]==a[q])

            q++;

        if(q==n)

        {

            q=p[n-1];

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
