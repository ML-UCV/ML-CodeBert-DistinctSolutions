#include <iostream>
#include <fstream>
using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



unsigned long long lgput(unsigned long long a, unsigned long long b, unsigned long long mod)

{

    unsigned long long r = 1;

    while(b)

    {

        if(b % 2 == 1)

            r = ( r % mod * a % mod ) % mod;

        a = ( a % mod * a % mod ) % mod;

        b /= 2;

    }

    return r;

}

unsigned long long phi(int n)

{

    unsigned long long p = 1, d = 2, fm, prod = 1;

    do

    {

        fm = 0;

        prod = 1;

        while(n % d == 0)

        {

            n /= d;

            prod = prod * d;

            fm ++;

        }

        if(fm > 0)

        {

            p = p * ( d - 1) * ( prod / d );

        }

        d ++;

        if(d * d > n && n > 1)

        {

            p = p * (n - 1);

            n = 1;

        }

    }while(n > 1);

    return p;

}

int main()

{

    int a, n;

    f >> a >> n;

    g << lgput(a, phi(n) - 1, n);

    return 0;

}
