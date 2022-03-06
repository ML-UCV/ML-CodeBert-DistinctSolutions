#include <iostream>
#include <fstream>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long a,b,x,y;

long long nsh(long long a,long long b,long long&x,long long&y)

{

    if(b==0)

    {

        x=1;y=0;return a;

    }

    long long x0,y0,d;

    d=nsh(b,a%b,x0,y0);

    x=y0;

    y=x0-(a/b)*y0;

    return d;

}

int main()

{

    f>>a>>b;

    nsh(a,b,x,y);

    if(x<0)x=b+x%b;

    g<<x;

}
