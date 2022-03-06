#include <bits/stdc++.h>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char t[2000005],p[2000005];

int a[2000005],urm[2000005];

int n,m,k;



void citire()

{

    fin.getline(p,2000005);

    fin.getline(t,2000005);

    n=strlen(p);m=strlen(t);

    fin.close();

}

void prefix()

{

    int j=0;

    for(int i=1;i<n;++i)

    {

        while(j>0&&p[i]!=p[j])

            j=urm[j-1];

        if(p[i]==p[j]) j++;

        urm[i]=j;

    }

}

void kmp()

{

    int q=0;

    for(int i=0;i<m;++i)

    {

        while(q>0&&p[q]!=t[i])

            q=urm[q-1];

        if(p[q]==t[i])q++;

        if(q==n)

            a[k++]=i-n+1;

    }

}

int main()

{

    citire();

    prefix();

    kmp();

    fout<<k<<'\n';

    if(k>1000) k=1000;

    for(int i=0;i<k;++i) fout<<a[i]<<' ';

    fout.close();

    return 0;

}
