#include <bits/stdc++.h>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");



int n,m,nr1,nr2,h1,h2,p1,p2,nrap;

bool fr[2000005];

string s,t;



void Read();

void RabinKarp();



int main()

{ Read();

    RabinKarp();

    return 0;

}



void Read()

{ f>>s>>t;

    n=s.size();

    m=t.size();

    p1=p2=1;

    for(int i=0; i<n; i++)

    { nr1=(nr1*27 +s[i])%100007;

        nr2=(nr2*29 +s[i])%666013;

        if(i)

        { p1=(p1*27)%100007;

            p2=(p2*29)%666013;

        }

    }

}



void RabinKarp()

{ if(n>m)

    { g<<0;

        return;

    }

    for(int i=0; i<n; i++)

    { h1=(h1*27 +t[i])%100007;

        h2=(h2*29 +t[i])%666013;

    }

    if(nr1==h1 && nr2==h2)

        nrap+=(fr[0]=1);

    for(int i=n; i<m; i++)

    { h1=((h1-(t[i-n]*p1)%100007 +100007)*27 +t[i])%100007;

        h2=((h2-(t[i-n]*p2)%666013 +666013)*29 +t[i])%666013;

        if(h1==nr1 && h2==nr2)

            nrap+=(fr[i-n+1]=1);

    }

    g<<nrap<<'\n';

    int nrSol=0;

    for(int i=0; i<2000005 && nrSol<1000; i++)

        if(fr[i])

        { nrSol++;

            g<<i<<' ';

        }

}
