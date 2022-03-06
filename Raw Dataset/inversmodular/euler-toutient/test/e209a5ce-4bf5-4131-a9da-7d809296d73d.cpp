#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int a, n, mod;



int Get_phi(int x)

{

    int phi = x;



    if(x % 2 == 0)

    {

        phi = phi / 2;

        while(x % 2 == 0)

            x /= 2;

    }



    int d = 3;



    while(x > 1 && d * d <= x)

    {

        if(x % d == 0)

        {

            phi = phi / d * (d - 1);

            while(x % d == 0)

                x /= d;

        }

        d += 2;

    }



    if(x > 1) phi = phi / x * (x - 1);



    return phi;

}



int Lgput(int b, int e)

{

    int p = 1;

    while(e)

    {

        if(e % 2) p = 1LL * p * b % mod;

        b = 1LL * b * b % mod;

        e /= 2;

    }



    return p;

}



int main()

{

    fin >> a >> n;



    mod = n;

    n = Get_phi(n);

    fout << Lgput(a, n - 1) << "\n";



    fin.close();

    fout.close();

    return 0;

}
