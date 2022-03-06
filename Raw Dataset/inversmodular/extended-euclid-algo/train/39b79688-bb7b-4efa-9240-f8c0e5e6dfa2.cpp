#include <cstdio>

int A, N;

void extendedEuclid(int A, int B, int& resultX, int& resultY) {
 if (B == 0) {
  resultX = 1;
  resultY = 0;
  return;
 }

 int prevResultX, prevResultY;
 extendedEuclid(B, A % B, prevResultX, prevResultY);

 resultX = prevResultY;
 resultY = prevResultX - (A / B) * prevResultY;
}

inline int positiveMod(int x, int MOD) {
 x %= MOD;
 if (x < 0) {
  x += MOD;
 }

 return x;
}

int main() {
 freopen("inversmodular.in", "r", stdin);
 freopen("inversmodular.out", "w", stdout);

 scanf("%d%d", &A, &N);

 int x, y;
 extendedEuclid(A, N, x, y);

 printf("%d\n", positiveMod(x, N));

 return 0;
}
