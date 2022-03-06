#include <cstdio>


using namespace std;



long long power(long long n, long long p, long long mod) {

 long long aux = n;

 n = 1;

 for(long long i=1; i<=p; i = i<<1) {

  if (p & i)

   n = aux * n % mod;

  aux = aux * aux % mod;

 }

 return n;

}





long long phi(int n) {

 long long res = n;



 for(long long i=2; i*i <= n; ++i)

  if (n%i == 0) {

   while (n%i == 0)

    n = n / i;

            res = res / i * (i-1);

  }

 if (n != 1)

  res = res / n * (n-1);



 return res;

}





int main() {

 freopen("inversmodular.in", "r", stdin);

 freopen("inversmodular.out", "w", stdout);



 long long a, n;

 scanf("%lld%lld", &a, &n);



 long long res = phi(n) - 1;



 printf("%lld\n", power(a, res, n));



 return 0;

}
