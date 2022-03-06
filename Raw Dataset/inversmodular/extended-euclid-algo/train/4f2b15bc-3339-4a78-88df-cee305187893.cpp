#include <bits/stdc++.h>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int a,n;

long long inv,ins;

void gcd(long long &x,long long &y,int a,int b)

{

    if(b==0)

        x=1,y=0;

    else

    {

        gcd(x,y,b,a%b);

        long long aux=x;

        x=y;

        y=aux-y*(a/b);

    }

}

int main()

{

    f>>a>>n;

    gcd(inv,ins,a,n);

    if(inv<=0)

        inv=(n+inv)%n;

    g<<inv;

    return 0;

}
