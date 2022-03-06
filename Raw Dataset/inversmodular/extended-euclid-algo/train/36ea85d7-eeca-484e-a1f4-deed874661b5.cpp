#include <fstream>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



void inv(long long a, long long b, long long &x, long long &y)

{

    if(!b)

        x=1,y=0;

    else

    {

        inv(b,a%b,x,y);

        long long aux=x;

        x=y;

        y=aux-y*(a/b);

    }

}

int main()

{

    long long a,mod,x,y;

    f>>a>>mod;

    inv(a,mod,x,y);

    while(x<=0)

        x=mod+x%mod;

    g<<x;

    f.close();

    g.close();

    return 0;

}
