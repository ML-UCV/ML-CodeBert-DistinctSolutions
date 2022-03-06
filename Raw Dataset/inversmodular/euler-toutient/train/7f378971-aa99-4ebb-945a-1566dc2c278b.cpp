#include <bits/stdc++.h>




using namespace std;



long long N,M;



long long getphi(long long nr){

 long long cur = nr;



 for(long long i = 2; i * i <= nr; ++i){

  if (nr % i == 0){

   while(nr % i == 0)

                nr /= i;

   cur = (cur / i) * (i - 1);

  }

 }



    if (nr != 1)

        cur = cur / nr * (nr - 1);



 return cur;

}



int main(){



 freopen("inversmodular.in","r",stdin);

 freopen("inversmodular.out","w",stdout);



 scanf("%lld %lld\n",&N,&M);



    long long put = getphi(M) - 1;

 long long nr = N;

 long long crt = 1;



    for(long long p = 1; p <= put; p <<= 1){

   if (p & put)

            crt = (crt * nr) % M;

    nr = (nr * nr) % M;

 }



 printf("%lld\n",crt);



 return 0;

}
