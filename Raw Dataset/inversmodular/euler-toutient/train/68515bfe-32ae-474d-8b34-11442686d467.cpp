#include <iostream>
#include <stdio.h>


using namespace std;



long long getphi(int n) {

    long long rez = n;

    int i = 2;

    while (i * i <= n) {

        if (n % i == 0) {

            rez = rez * (i - 1) / i;

            while (n % i == 0)

                n /= i;

        }

        i++;

    }

    if (n != 1)

        rez = rez * (n - 1) / n;

    return rez;

}





long long lgput (long long n, long long p, long long mod) {

    long long rez = 1;

    while (p > 0) {

        if (p % 2 == 0) {

            n = (n % mod) * n % mod;

            p = p / 2;

        }

        else {

            rez = rez * (n % mod) % mod;

            p--;

        }

    }

    return rez;

}



int main() {



    freopen ("inversmodular.in", "r", stdin);

    freopen ("inversmodular.out", "w", stdout);



    long long A, N, put;



    scanf ("%lld%lld", &A, &N);



    put = getphi(N) - 1;

    printf ("%lld", lgput(A, put, N));





    return 0;

}
