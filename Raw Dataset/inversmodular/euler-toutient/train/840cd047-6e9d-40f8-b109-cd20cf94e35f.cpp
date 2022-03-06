#include <bits/stdc++.h>


using namespace std;



ifstream ci ("inversmodular.in");

ofstream co ("inversmodular.out");



long long putere (long long a,long long n,long long m)

{

    long long p=1;

    while (n)

    {

        if (n%2!=0)

        {

            p=p*a%m;

        }

        n/=2;

        a=a*a%m;

    }

    return p;

}



int main()

{

    long long a,n,b,d=2, nn;

    ci >> a >> n;

    nn = n;

    b=n;

    while (d*d<=n)

    {

        if(n%d==0)

        {

            b=b/d*(d-1);

            while (n%d==0)

            {

                n/=d;

            }

        }

        d++;

    }

    if(n>1)

    {

        b=b/n*(n-1);

    }

    co << putere(a,b-1,nn);

    return 0;

}
