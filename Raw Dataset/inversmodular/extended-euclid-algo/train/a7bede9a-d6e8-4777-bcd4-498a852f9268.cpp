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
 std::ifstream cin("inversmodular.in");
 std::ofstream cout("inversmodular.out");
 std::ios::sync_with_stdio(false);

 int a, n;
 long long inv = 0, y;

 cin >> a >> n;
 euclid_extins(a, n, inv, y);

 if (inv <= 0) {
  inv = n + inv % n;
 }

 cout << (long long)inv << '\n';

 return 0;
}
