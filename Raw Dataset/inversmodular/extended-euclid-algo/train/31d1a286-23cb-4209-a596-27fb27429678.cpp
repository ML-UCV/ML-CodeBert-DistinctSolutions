#include <fstream>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long x,y,a,n;

void euclid(long long &x,long long &y,int a,int b)

{

    if(!b)

    {

        x=1;

        y=0;

    }

    else

    {

        euclid(x,y,b,a%b);

        long long aux=x;

        x=y;

        y=aux-y*(a/b);

    }

}

int main()

{f>>a>>n;

euclid(x,y,a,n);

if(x<=0)

    x=n+x%n;

g<<x;



    return 0;

}
