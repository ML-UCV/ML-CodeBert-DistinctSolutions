#include <bits/stdc++.h>


using namespace std;



ifstream si("strmatch.in");

ofstream so("strmatch.out");



string s,s2;

int n,b=101,m1=100007,m2=100021,rs,h1,h2,m,i,hash1,hash2,p1,p2,v[1001];



int main()

{

    si>>s>>s2;

    n=s.length();

    m=s2.length();

    p1=1;

    p2=1;

    for(i=0; i<n; i++)

    {

        hash1=hash1*b%m1+s[i];

        hash2=hash2*b%m2+s[i];

        if(i!=0)

        {

            p1=p1*b%m1;

            p2=p2*b%m2;

        }

    }

    if(n>m)

    {

        so<<0<<'\n';

        return 0;

    }

    for(i=0; i<n; i++)

    {

        h1=h1*b%m1+s2[i];

        h2=h2*b%m2+s2[i];

    }

    if(h1==hash1 && h2==hash2)

    {

        rs++;

        v[rs]=0;

    }

    for(i=n; i<m; i++)

    {

        h1=((h1-s2[i-n]*p1%m1+m1)*b+s2[i])%m1;

        h2=((h2-s2[i-n]*p2%m2+m2)*b+s2[i])%m2;

        if(h1==hash1 && h2==hash2)

        {

            rs++;

            if(rs<=1000)

            {

                v[rs]=i-n+1;

            }

        }

    }

    so<<rs<<'\n';

    if(1000<rs) rs=1000;

    for(i=1; i<=rs; i++)

    {

        so<<v[i]<<" ";

    }



    return 0;

}
