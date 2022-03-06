#include <bits/stdc++.h>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long A, N;



void read()

{

    f >> A >> N;

}



long long expLg(long long x, long long p)

{

    long long y = 1;

    while (p > 1) {

        if (p & 1)

            y = (x * y) % N;

        x = (x * x) % N;

        p >>= 1;

    }

    return (x * y) % N;

}



long long phi(long long x)

{

    long long res = x;

    for (int i = 2; i * i <= x; ++i)

        if (x % i == 0) {

            while (x % i == 0)

                x /= i;

            res = (res / i) * (i - 1);

        }

    if (x > 1)

        res = (res / x) * (x - 1);

    return res;

}



void show()

{

    g << expLg(A, phi(N) - 1);

}



int main()

{

    read();

    show();

    return 0;

}
