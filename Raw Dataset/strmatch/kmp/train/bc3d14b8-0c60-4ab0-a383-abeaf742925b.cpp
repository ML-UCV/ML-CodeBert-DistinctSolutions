#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

int n,m,l,i,j;

int nr[2000002],urm[2000002];

string p,t;

void prefix(int n,string p){

  int i,j;

  urm[0]=0; j=0;

  for(i=1;i<n;i++){

    while(j>0&&p[i]!=p[j])

        j=urm[j-1];

    if(p[j]==p[i])

        j++;

    urm[i]=j;

  }

}

int main()

{

    f>>p>>t;

    n=p.size(); m=t.size();

    prefix(n,p);

    j=0; l=0;

    for(i=0;i<m;i++){

        while(j>0&&p[j]!=t[i])

            j=urm[j-1];

        if(p[j]==t[i])

            j++;

        if(j==n){

          l++;

          nr[l]=i-n+1;

        }

    }

    g<<l<<'\n';

    for(i=1;i<=min(l,1000);i++)

        g<<nr[i]<<' ';

    return 0;

}
