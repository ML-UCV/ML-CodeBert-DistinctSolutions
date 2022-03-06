#include <fstream>
#include <stdio.h>



void euclid_extins(int a, int b, long long &x, long long &y) {
 if (b == 0) {
  x = 1;
  y = 0;
 } else {
  euclid_extins(b, a % b, x, y);
  long long temp = x;
  x = y;
  y = temp - (a / b) * y;
 }
}

int main() {



 freopen("inversmodular.in", "r", stdin);
    freopen("inversmodular.out", "w", stdout);

 int a, n;
 long long inv = 0, y;


 scanf("%d%d", &a, &n);
 euclid_extins(a, n, inv, y);

 if (inv <= 0) {
  inv = n + inv % n;
 }

 printf("%lld\n", inv);


 return 0;
}
