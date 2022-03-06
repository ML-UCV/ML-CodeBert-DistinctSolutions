#include <bits/stdc++.h>




using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int N, A;



int LogPow(int x, int n)

{

    if (n == 0) return 1;

    else if (n % 2 == 0) return LogPow(1LL * x * x % N, n / 2);

    else return 1LL * x * LogPow(1LL * x * x % N, n / 2) % N;

}



int phi(int N)

{

    int p = N;

    for (int i = 2; i * i <= N; i += 1 + i % 2)

        if (N % i == 0)

        {

            while (N % i == 0)

                N /= i;

            p = p / i * (i - 1);

        }

    if (N > 1)

        p = p / N * (N - 1);

    return p;

}



int main()

{

    fin >> A >> N;

    fout << LogPow(A, phi(N) - 1);

    return 0;

}
