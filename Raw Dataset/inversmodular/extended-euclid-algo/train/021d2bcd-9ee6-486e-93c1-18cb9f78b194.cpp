#include <bits/stdc++.h>


using namespace std;

ifstream f ( "inversmodular.in" );

ofstream g ( "inversmodular.out" );

void cmmdc(long long a,long long b,long long &x,long long &y)

{ if(!b)

    { x=1;

        y=0;

    }

    else

    { long long xi,yi;

        cmmdc(b,a%b,xi,yi);

        x=yi;

        y=xi-(a/b)*yi;

    }

}

int main()

{

    long long a,b;

    f>>a>>b;

    long long y,sol;

    cmmdc(a,b,sol,y);

    if(sol<=0) sol += b;



    g<<sol;

    return 0;

}
