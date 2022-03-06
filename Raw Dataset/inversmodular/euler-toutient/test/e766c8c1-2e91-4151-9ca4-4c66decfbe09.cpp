#include <bits/stdc++.h>


std::ifstream fin ("inversmodular.in");

std::ofstream fout ("inversmodular.out");



int64_t Pow(int64_t a, int64_t p, int64_t m)

{

    int64_t res = 1;

    while (p > 0)

    {

        if (p % 2 == 1)

        {

            res = (res * a) % m;

        }

        a = (a * a) % m;

        p /= 2;

    }

    return res;

}



int64_t Phi(int64_t n)

{

    int64_t r = 1, d = 2, p = 0;

    while (n > 1)

    {

        p = 0;

        while (n % d == 0)

        {

            n /= d;

            ++p;

        }

        if (p != 0)

        {

            r *= (d - 1) * Pow(d, p - 1, LONG_LONG_MAX);

        }

        ++d;

        if(n > 1 && d * d > n)

        {

            d = n;

        }

    }

    return r;

}



int64_t InversModular(const int64_t & a, const int64_t & n)

{

    return Pow(a, Phi(n) - 1, n);

}



int main()

{

    int64_t a, n;



    fin >> a >> n;



    fout << InversModular(a, n);



    return 0;

}
