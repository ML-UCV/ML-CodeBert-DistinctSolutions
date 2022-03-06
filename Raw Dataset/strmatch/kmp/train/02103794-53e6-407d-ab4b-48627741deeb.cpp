#include <bits/stdc++.h>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



int const lim = 2000005;

char a[lim],b[lim];

int n,m,k,pi[lim],d[lim],mx;

vector < int > c;



int main()

{

    in>>a+1>>b+1;

    n=strlen(a+1);

    m=strlen(b+1);



    pi[1]=0;

    k=0;

    for(int i=2;i<=n;i++)

    {

        while(k>0 && a[i]!=a[k+1])

            k=pi[k];



        if(a[i]==a[k+1])

            k++;



        pi[i]=k;

    }



    k=0;

    for(int i=1;i<=m;i++)

    {

        while(k>0 && b[i]!=a[k+1])

            k=pi[k];



        if(b[i]==a[k+1])

            k++;



        d[i]=k;

        if(d[i]==n)

        {

            mx++;

            if(c.size()<1000)

            {

                c.push_back(i-n);

            }

        }

    }



    out<<mx<<'\n';

    for(int i=0;i<c.size();i++)

        out<<c[i]<<" ";

}
