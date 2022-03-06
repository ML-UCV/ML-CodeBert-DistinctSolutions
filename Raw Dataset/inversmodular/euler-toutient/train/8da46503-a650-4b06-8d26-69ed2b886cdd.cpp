#include <bits/stdc++.h>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long a, mod;

long long phi(long long);

long long lgput(long long, long long);

int main()

{

    f >> a >> mod;

    g << lgput(a, phi(mod) - 1);

    return 0;

}

long long lgput(long long a, long long b)

{

    long long rez = 1;

    for (long long i = 1; b; i <<= 1)

    {

        if (i & b)

            b ^= i, rez *= a, rez %= mod;

        a *= a;

        a %= mod;

    }

    return rez;

}

long long phi(long long x)

{

    long long rez = x;

    bool ok = 0;

    while (x % 2 == 0)

        x /= 2, ok = 1;

    if (ok)

        rez /= 2;

    ok = 0;

    for (long long d = 3; d * d <= x; d += 2)

    {

        while (x % d == 0)

            x /= d, ok = 1;

        if (ok)

            rez /= d, rez *= d - 1, ok = 0;

    }

    if (x != 1)

        rez /= x, rez *= x - 1;

    return rez;

}
