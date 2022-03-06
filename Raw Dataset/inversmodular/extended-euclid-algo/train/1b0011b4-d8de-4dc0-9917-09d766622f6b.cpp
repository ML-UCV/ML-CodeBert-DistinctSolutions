#include <bits/stdc++.h>

using namespace std;

void invMod(int a, int b, int &x, int &y) {
 if (!b)
  x = 1, y = 0;
 else {
  int x0, y0;
  invMod(b, a % b, x0, y0);
  x = y0;
  y = x0 - (a / b) * y0;
 }
}

int main() {
 ifstream cin ("inversmodular.in");
 ofstream cout ("inversmodular.out");
 int a, p;
 cin >> a >> p;
 int x, y;
 invMod(a, p, x, y);
 if (x <= 0)
  x += p;
 cout << x;
 return 0;
}
