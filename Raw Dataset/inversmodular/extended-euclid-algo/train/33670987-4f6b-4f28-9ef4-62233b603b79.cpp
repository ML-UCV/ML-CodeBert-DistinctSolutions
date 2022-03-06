#include<fstream>
using namespace std;

long long a, b, x, y;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



void gcd_extended(long long a, long long b, long long &x, long long &y) {

 if (!b) {

   x = 1;

   y = 0;

 }

 else {

   long long x0, y0;

   gcd_extended(b, a % b, x0, y0);

   x = y0;

   y = x0 - (a / b) * y0;

 }

}



int main() {

  f >> a >> b;

  gcd_extended(a, b, x, y);

  while (x < 0)

    x += b;

  g << x;

  return 0;

}
