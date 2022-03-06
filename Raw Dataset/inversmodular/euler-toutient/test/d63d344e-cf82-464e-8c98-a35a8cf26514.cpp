#include <bits/stdc++.h>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



long long A, N;



long long phi(int x)

{

    long long result = x * 1LL;

    for (int i = 2; i * i <= x; ++i)

    {

        if (x % i == 0)

        {

            while (x % i == 0)

                x = x / i;

            result *= (i - 1);

            result /= i;

        }

    }

    if (x > 1)

    {

        result *= (x - 1);

        result /= x;

    }

    return result;

}



long long log2pow(long long n, long long p)

{

    if (p == 0)

        return 1;

    long long x = log2pow(n, p / 2);

    if (p % 2 == 0)

        return x * x % N;

    return (n * x % N * x) % N;

}



int main()

{

    fin >> A >> N;

    fout << log2pow(A, phi(N) - 1);

    return 0;

}
