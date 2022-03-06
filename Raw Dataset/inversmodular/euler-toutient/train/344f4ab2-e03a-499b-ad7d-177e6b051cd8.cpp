#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");
int Fact(int n, int P)

{

    int rez = 1;

    for(int i = 2;i <= n;i++)

        rez = rez * i % P;

    return rez;

}



int LogP(int a, int n, int P)

{

    int rez = 1;

    while(n > 0)

    {

        if(n % 2 == 1)

            rez = 1LL * rez * a % P;

        n /= 2;

        a = 1LL * a * a % P;

    }

    return rez;

}



int Phi(int n)

{

    int f,exp,phi = n;

    f = 2;

    while(n > 1)

    {

        exp = 0;

        while(n % f == 0)

        {

            n /= f;

            exp++;

        }

        if(exp > 0) phi = phi / f * (f - 1);

        if(f * f < n) f++;

        else f = n;

    }

    return phi;

}



int main()

{

    int a, N;

    fin >> a >> N;

    fout << LogP(a, Phi(N) - 1, N);

    return 0;

}
