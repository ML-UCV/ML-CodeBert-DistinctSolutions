#include <bits/stdc++.h>




using namespace std;



long long N,M;



long long phi(long long n) {

    long long result = n;



    for (long long p = 2; p * p <= n; ++p) {

        if (n % p == 0) {

            while (n % p == 0)

                n /= p;

            result *= (1.0 - (1.0 / (float)p));

        }

    }

    if (n > 1)

        result *= (1.0 - (1.0 / (float)n));



    return result;

}



int main(){



 freopen("inversmodular.in","r",stdin);

 freopen("inversmodular.out","w",stdout);



 scanf("%lld %lld\n",&N,&M);



    long long put = phi(M) - 1;

 long long nr = N;

 long long crt = 1;



    for(long long p = 1; p <= put; p <<= 1){

   if (p & put)

            crt = (crt * nr) % M;

    nr = (nr * nr) % M;

 }



 printf("%lld",crt);



 return 0;

}
