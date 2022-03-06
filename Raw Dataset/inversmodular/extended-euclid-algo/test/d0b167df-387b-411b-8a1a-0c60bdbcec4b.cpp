#include <fstream>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int t,a,n,inv,inv2;

void euclid(int &inv, int &inv2, int a, int n)

{

    if(n==0)

    {

        inv=1;

        inv2=0;

    }

    else

    {

        int inv0, inv20;

        euclid(inv,inv2,n,a%n);

        inv0=inv;

        inv20=inv2;

        inv=inv20;

        inv2=inv0-(a/n)*inv20;

    }

}

int main()

{

        f>>a>>n;

        euclid(inv,inv2,a,n);

        while(inv<0)

            inv=inv+n;

        g<<inv;

    return 0;

}
