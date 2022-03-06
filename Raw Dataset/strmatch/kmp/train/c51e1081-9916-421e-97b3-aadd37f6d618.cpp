#include <bits/stdc++.h>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

string a,b,t1,t2;

int poz,i,pozitiea,pozitieb,pozitie,l1,l2,numar,ok,j;

int v[1010],p[2000010];

void precalc()

{

    p[0]=-1;

    poz=-1;

    for(i=1;i<l1;i++)

    {

        while(poz!=-1 && a[poz+1]!=a[i])

            poz=p[poz];

        if(a[poz+1]==a[i])

            poz++;

        p[i]=poz;

    }

}

int main()

{

    fin>>a>>b;

    l1=a.size();

    l2=b.size();

    if(l1>l2)

    {

        fout<<0;

        return 0;

    }

    poz=-1;

    precalc();



    poz=-1;

    for(i=0; i<l2; i++)

    {

        while(poz!=-1 && poz+1<l1 && a[poz+1]!=b[i] )

            poz=p[poz];

        if(poz+1<l1 &&a[poz+1]==b[i])

            poz++;

        if(poz==l1-1)

        {

            poz=p[l1-1];

            numar++;

            if(numar<=1000)

                v[numar]=i-l1+1;

        }

    }

    fout<<numar<<'\n';

    numar=min(numar,1000);

    for(i=1; i<=numar; i++)

        fout<<v[i]<<" ";

    return 0;

}
