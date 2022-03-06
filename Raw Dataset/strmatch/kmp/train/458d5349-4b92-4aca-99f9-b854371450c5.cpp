#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



void Citire();

void Pref();

void KMP();



char T[2000005],P[2000005];

int n,m,k;

int a[2000005],urm[2000005];





int main()

{

    Citire();

    KMP();

    fout<<k<<'\n';

    if(k>1000) k=1000;

    for(int i=1;i<=k;++i)

        fout<<a[i]<<' ';

    return 0;

}



void Citire()

{

    fin.getline(P,2000005);

    fin.getline(T,2000005);

    n=strlen(P);

    m=strlen(T);

}



void Pref()

{

    int j=0;

    for(int i=1;i<n;++i)

    {

        while(j>0 && P[i]!=P[j]) j=urm[j-1];

        if(P[i] == P[j]) ++j;

        urm[i]=j;

    }

}



void KMP()

{

    Pref();

    int q=0;

    for(int i=0;i<m;++i)

    {

        while(q>0 && P[q]!=T[i]) q=urm[q-1];

        if(P[q]==T[i]) ++q;

        if(q==n) a[++k]=i-n+1;

    }

}
