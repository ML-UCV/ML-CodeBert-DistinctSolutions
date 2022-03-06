#include <bits/stdc++.h>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int phi(int n)

{





    int sol = n, p;

    for(p = 2; p * p <= n && n > 1; p++)

    {

        if(n % p == 0)

            sol = sol / p * (p - 1);

        while(n % p == 0)

            n /= p;

    }

    if(n > 1) sol = sol / n * (n - 1);



    return sol;

}



int lgput(int a, int n, int mod)

{

    int p = 1;

    while(n)

    {

        if(n % 2 == 1) p = 1LL * p * a % mod;

        n /= 2;

        a = 1LL * a * a % mod;

    }

    return p;

}



int main()

{

    int a, n;

    fin >> a >> n;

    fout << (lgput(a, (phi(n) - 1), n));

    return 0;

}
