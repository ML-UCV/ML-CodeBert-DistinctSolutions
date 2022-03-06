#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int a,n;

void Euclid(int a,int b,long long& x,long long& y)

{

    if(b==0)

    {

        x=1;

        y=0;

    }

    else

    {

        long long x0,y0;

        Euclid(b,a%b,x0,y0);

        x=y0;

        y=(x0-a/b*y0);

    }

}

int main()
{

    long long x,y;

    f>>a>>n;

    f.close();

    Euclid(a,n,x,y);

    x=((x%n)+n)%n;

    g<<x;

    return 0;
}
