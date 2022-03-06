#include <bits/stdc++.h>


using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



int n,m,k,i,nr,sol[1010],p[2000010];

char s[2000010],c[2000010];



int main()

{

    f>>(c+1);n=strlen(c+1);

    f>>(s+1);m=strlen(s+1);



    for(i=2;i<=n;i++)

    {

        while(k!=0 && c[k+1]!=c[i])k=p[k];

        if(c[k+1]==c[i])k++;

        p[i]=k;

    }



    k=0;

    for(i=1;i<=m;i++)

    {

        while(k!=0 && c[k+1]!=s[i])k=p[k];

        if(c[k+1]==s[i])k++;



        if(k==n)

        {

            nr++;

            if(nr<=1000)sol[nr]=i-n;

        }

    }



    g<<nr<<'\n';

    for(i=1;i<=min(nr,1000);i++)g<<sol[i]<<" ";

    return 0;

}
