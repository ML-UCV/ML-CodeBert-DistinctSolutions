#include <bits/stdc++.h>
using namespace std;

ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");

int a, n, ind;

int putere(long long a, long long b)

{

    long long p = 1;

    while(b)

    {

        if(b%2==1)

            p=(p*a)%n;

        a=(a*a)%n;

        b/=2;

    }

    return p;

}

int indicator(int n)

{

    int f = 2, p, rez = 1;

    while(f*f<=n)

    {

        if(n%f == 0)

        {

             p = 0;

             while(n%f==0)

             {

                 p++;

                 n/=f;

             }

             rez*=putere(f, p-1)*(f-1);

        }

        f++;

    }

    if(n > 1)

        rez*=(n-1);

    return rez;

}

int main()

{

    fin >> a >> n;

    ind = indicator(n);

    a = putere(a, ind-1);

    fout << a;

    return 0;

}
