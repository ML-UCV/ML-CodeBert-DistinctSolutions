#include <bits/stdc++.h>


using namespace std;







ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



long long sigma(long long n)

{

    long long rez = n;



    if(n % 2 == 0)

    {

        rez /= 2;



        while(n % 2 == 0)

            n /= 2;

    }



    for(long long i = 3; i * i <= n; i += 2)

    {

        if(n % i == 0)

        {

            rez /= i;

            rez *= (i - 1);



            while(n % i == 0)

                n /= i;

        }

    }



    if(n != 1)

    {

        rez /= n;

        rez *= (n - 1);

    }



    return rez;

}





long long lgput(long long n,long long p, long long b)

{

    long long rez = 1;

    long long x = n;



    while(p > 0)

    {

        if(p & 1)

        {

            rez = (rez * x) % b;

        }

        x = (x * x) % b;

        p >>= 1;

    }



    return rez;

}



 main()

{

    long long a, b;

    in >> a >> b;



    long long p = sigma(b) - 1;



    out << lgput(a,p,b);



    return 0;

}
