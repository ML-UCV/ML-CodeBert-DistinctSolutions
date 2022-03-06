#include <bits/stdc++.h>
using namespace std;

unsigned long long a, MOD, x, d, fi, fm, i;

unsigned long long rez;

unsigned long long paw(int a, int b)

{

    unsigned long long r = 1, A = a;

    if(b == 0)return 1;

    while(b > 1)

    {

        if(b % 2 == 1)r = (r * A) % MOD;

        A = (A * A) % MOD;

        b = b / 2;

    }

    return (r * A) % MOD;

}

int main()

{

    ifstream f("inversmodular.in");

    ofstream g("inversmodular.out");

    f >> a >> MOD;



    x = MOD;

    d = 2;

    fi = 1;

    do

    {

        fm = 0;

        while(x % d == 0)

        {

            x = x / d;

            fm ++;

        }

        if(fm > 0)fi = (fi * paw(d, fm - 1) * (d - 1)) % MOD;

        d ++;

        if(d * d > x && x != 1)fi = (fi * (x - 1)) % MOD, x = 1;

    }while(x != 1);

    g << paw(a, fi - 1) % MOD << "\n";

    return 0;

}
