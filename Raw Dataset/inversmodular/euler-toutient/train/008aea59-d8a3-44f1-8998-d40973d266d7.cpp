#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int LogP(int a, int n, int P)

{

    int rez = 1;

    while(n > 0)

    {

        if (n % 2 == 1)

            rez = 1LL * rez * a % P;

        n /= 2;

        a = 1LL * a * a % P;

    }

    return rez;

}



int Phi(int n)

{

    int f = 2, e, phi = n;

    while(n > 1)

    {

        e = 0;

        while(n % f == 0)

        {

            e++;

            n/=f;

        }

        if(e > 0) phi = phi / f * (f - 1);

        if(f * f < n) f++;

        else f = n;

    }



    return phi;

}



int main()

{

    long long a, P;

    fin >> a >> P;

    fout << LogP(a, Phi(P) - 1, P);



    return 0;

}
