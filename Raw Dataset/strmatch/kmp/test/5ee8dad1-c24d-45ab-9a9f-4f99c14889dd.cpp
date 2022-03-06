#include<bits/stdc++.h>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char a[2000010],b[2000010];

int n,m,i,p[2000010],k,sol,s[2000010];

int main()

{

    fin>>a+1>>b+1;

    n=strlen(a+1);m=strlen(b+1);

    for(i=2;i<=n;i++)

    {

        while(k!=0&&a[i]!=a[k+1]) k=p[k];

        if(a[i]==a[k+1]) k++;

        p[i]=k;

    }k=0;

    for(i=1;i<=m;i++)

    {

        while(k!=0&&b[i]!=a[k+1]) k=p[k];

        if(b[i]==a[k+1]) k++;

        if(k==n) s[++sol]=i-n;

    }

    fout<<sol<<"\n";

    for(i=1;i<=sol&&i<=1000;i++) fout<<s[i]<<" ";

    return 0;

}
