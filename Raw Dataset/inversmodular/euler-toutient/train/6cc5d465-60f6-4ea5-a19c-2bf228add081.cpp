#include <fstream>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int a,n;



int phi(int x)

{

    int p=x;

    for (int i=2;i*i<=x;i++)

        if (x%i==0)

        {

            while (x%i==0)

                x/=i;

            p=(p/i)*(i-1);

        }

    if (x!=1)

        p=(p/x)*(x-1);

    return p;

}



int inv_mod(int x, int mod)

{

    int p = phi(mod) - 1;

    int rez = 1;

    while (p)

    {

        if (p%2)

            rez = (1LL * rez * x) % mod;

        x = (1LL * x * x) % mod;

        p = p / 2;

    }

    return rez;

}



int main()

{

    f>>a>>n;

    g<<inv_mod(a, n);

    return 0;

}
