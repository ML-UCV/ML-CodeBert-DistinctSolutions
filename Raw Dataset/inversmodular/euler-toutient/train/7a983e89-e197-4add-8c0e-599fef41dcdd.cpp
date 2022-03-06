#include <cstdio>
using namespace std;

int euler(int a)

{

    int phi = a , d , e;

    d = 2;

    while(1LL * d * d <= a && a > 1)

    {

        e = 0;

        while(a % d == 0)

        {

            a = a / d;

            e ++;

        }

        if(e > 0)

            phi = phi / d * (d - 1);

        d ++;

    }

    if(a > 1)

        phi = phi / a * (a - 1);

    return phi;

}

long long fast_pow(int a , int b , int MOD)

{

    long long aa = a , p;

    for(p = 1 ; b ; b = b >> 1)

    {

        if(b & 1)

            p = (p * aa) % MOD;

        aa = (aa * aa) % MOD;

    }

    return p;

}

int main()

{

    freopen("inversmodular.in" , "r" , stdin);

    freopen("inversmodular.out" , "w" , stdout);

    int a , n;

    scanf("%d%d" , &a , &n);

    printf("%lld\n" , fast_pow(a , euler(n) - 1 , n));

    return 0;

}
