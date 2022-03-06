#include <cstdio>

int A, N;

int totient(int N) {
 int result = N;
 for (int i = 2; i * i <= N; i++) {
  if (N % i == 0) {
   result = result / i * (i - 1);
   while (N % i == 0) {
    N /= i;
   }
  }
 }

 if (N != 1) {
  result = result / N * (N - 1);
 }

 return result;
}

int lgput(int base, int exponent, int MOD) {
 int result = 1, basePow2Value = base;
 for (int powIdx = 0; (1LL << powIdx) <= exponent; powIdx++) {
  if (exponent & (1 << powIdx)) {
   result = (1LL * result * basePow2Value) % MOD;
  }

  basePow2Value = (1LL * basePow2Value * basePow2Value) % MOD;
 }

 return result;
}

int main() {
 freopen("inversmodular.in", "r", stdin);
 freopen("inversmodular.out", "w", stdout);

 scanf("%d%d", &A, &N);
 printf("%d\n", lgput(A, totient(N) - 1, N));
 return 0;
}
