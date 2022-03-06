#include <bits/stdc++.h>


using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



int N,M,k,nr,i,p[2000010],sol[1010];

char c[2000010],s[2000010];



int main()

{

    f>>(c+1);

    f>>(s+1);



    N=strlen(c+1);

    M=strlen(s+1);



    p[1]=0;

    k=0;



    for(i=2;i<=N;i++)

    {

        while(k!=0 && c[k+1]!=c[i])k=p[k];

        if(c[k+1]==c[i])k++;

        p[i]=k;

    }



    k=0;

    for(i=1;i<=M;i++)

    {

        while(k!=0 && c[k+1]!=s[i])k=p[k];

        if(c[k+1]==s[i])k++;



        if(k==N)

        {

            nr++;

            if(nr<=1000)

            {

                sol[nr]=i-N;

            }

        }

    }



    g<<nr<<'\n';

    for(i=1;i<=min(nr,1000);i++)g<<sol[i]<<" ";

    return 0;

}
