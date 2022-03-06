#include <bits/stdc++.h>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int n, mod, phi=1, ex(int, int);

void desc(int);

int main()

{

    f >> n >> mod;

    desc(mod);

    g << ex(n, phi - 1);

    return 0;

}

void desc(int N)

{

    int d = 3;

    if(N % 2 == 0)

    {

        N /= 2;

        while(N % 2 == 0)

            N /= 2, phi *= 2;

    }

    while(d * d <= N)

    {

        if(N % d == 0)

        {

            N /= d;

            phi *= (d - 1);

            while(N % d == 0)

                N /=d, phi *= d;

        }

        d += 2;

    }

    if(N > 1)

        phi *= N - 1;

}

int ex(int b, int exponent)

{

    if(!exponent)

        return 1;

    int r = ex(b, exponent / 2);

    r = 1LL * r * r % mod;

    if(exponent % 2)

        r = 1LL * r * b % mod;

    return r;

}
