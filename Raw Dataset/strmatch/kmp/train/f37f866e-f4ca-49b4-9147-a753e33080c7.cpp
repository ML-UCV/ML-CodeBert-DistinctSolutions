#include <bits/stdc++.h>


using namespace std;



int m,n;

char a[2000001], b[2000001];

int pi[2000001], pos[1024];

int ct;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



void Peg();

void Read();

void Rez();

void Afis();



int main()

{

    Read();

    Peg();

    Rez();

    Afis();

    return 0;

}



void Read()

{

    fin.getline(a,2000001);

    fin.getline(b,2000001);

    m=strlen(a);

    n=strlen(b);

    for(int i=n;i;i--) b[i]=b[i-1];

    for(int i=m;i;i--) a[i]=a[i-1];

    b[0]=a[0]=' ';

}



void Peg()

{

    pi[1]=0;

    int q=0;

 for(int i=2;i<=m;i++)

 {

  while(q && a[q+1]!=a[i]) q=pi[q];

  if(a[q+1]==a[i]) q++;

  pi[i]=q;

 }

}



void Rez()

{

    int q=0;

    for(int i=1;i<=n;i++)

 {

  while(q && a[q+1]!=b[i]) q=pi[q];

  if(a[q+1]==b[i]) q++;

  if(q==m)

  {

   q=pi[m];

   ct++;

   if(ct<=1000)

    pos[ct]=i-m;

  }

 }

}



void Afis()

{

    fout<<ct<<'\n';

    for(int i=1;i<=min(ct,1000);i++)

        fout<<pos[i]<<' ';

}
