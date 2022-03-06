#include <bits/stdc++.h>


using namespace std;

ifstream in("inversmodular.in");

ofstream out("inversmodular.out");

long long lgput(long long a, long long p, long long mod)

{

    long long res = 1;

    while(p > 0)

    {

        if(p % 2 == 1)

            res = (1LL * res * a) % mod;

        a = (1LL * a * a) % mod;

        p /= 2;

    }

    return res;

}

long long f(long long n)

{

    long long r = 1, d = 2;

    while(n > 1)

    {

        long long put = 0;

        while(n % d == 0)

        {

            n /= d;

            put ++;

        }

        if(put != 0)

            r *= 1LL * (d - 1) * lgput(d, put - 1, 20000000000000);

        d ++;

        if(n > 1 && d * d > n)

            d = n;

    }

    return r;

}

int32_t main()

{

    long long a, n;

    in >> a >> n;

    out << lgput(a, f(n) - 1, n);

    return 0;

}
