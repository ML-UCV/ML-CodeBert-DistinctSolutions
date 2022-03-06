#include <cstdio>
#include <iostream>


using namespace std;



long long a, n, nr;



void descomp(long long x)

{

    if(x%2 == 0)

    {

        while(x%2 == 0)

        {

            x/=2;

        }

        nr=nr/2;

    }

    for(int i=3; i*i<=x; i+=2)

    {

        if(x%i == 0)

        {

            while(x%i == 0)

            {

                x/=i;

            }

            nr=nr/i*(i-1);

        }

    }

    if(x != 1)

    {

        nr=nr/x*(x-1);

    }

}



long long putere(long long x, long long p)

{

    long long rez=1;

    while(p)

    {

        if(p&1)

        {

            p--;

            rez=(rez*x)%n;

        }

        p>>=1;

        x=(x*x)%n;

    }

    return rez%n;



}







int main()

{

    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);



    scanf("%lld %lld", &a, &n);

    nr=n;

    descomp(n);

    printf("%lld", putere(a, nr-1)%n);



    return 0;

}
