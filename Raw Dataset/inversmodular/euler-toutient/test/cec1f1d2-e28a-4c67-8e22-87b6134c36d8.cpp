#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");
long long phi_de_n(long long n)

{

    int phin;

    phin = n;

    for(int i = 2; i * i <= n; ++i)

    {

        if(n % i == 0)

        {

            phin /= i;

            phin *= (i - 1);

            while(n % i == 0)

            {

                n /= i;

            }

        }

    }

    if(n != 1)

    {

        phin /= n;

        phin *= (n - 1);

    }

    phin -= 1;

    return phin;

}



int main()

{

    long long a,n;

    fin >> a >> n;

    long long doru = 1;

    long long phin = phi_de_n(n);

    for(long long i = 1; i <= phin; i <<= 1)

    {

        if(i & phin)doru = (doru * a) % n;

        a = (a * a) % n;

    }

    fout << doru;

    return 0;

}
