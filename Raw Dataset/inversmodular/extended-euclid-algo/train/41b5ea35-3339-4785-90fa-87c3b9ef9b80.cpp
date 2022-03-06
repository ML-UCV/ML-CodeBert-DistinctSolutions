#include <bits/stdc++.h>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long a,b,d,x,y;

long long gcd (long long a,long long b,long long &x,long long &y)

{

    if (b==0)

    {

        x=1;

        y=0;

        return a;

    }

    long long x0,y0,d;

    d=gcd(b,a%b,x0,y0);

    x=y0;

    y=x0-(a/b)*y0;

    return d;

}

int main()

{

    f>>a>>b;

    d=gcd(a,b,x,y);

    if (x<=0)

    {

        x=(x+b)%b;

    }

    g<<x;

    return 0;

}
