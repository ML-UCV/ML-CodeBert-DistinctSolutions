#include <bits/stdc++.h>

using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

void euclid(int a,int b,int &x,int &y)
{
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  int x0, y0;
  euclid(b, a%b, x0, y0);
  x = y0;
  y = x0 - (a / b) * y0;
}

int main()
{
  int n;
  int a, b;

  fin >> a >> b;

  int x, y;
  euclid(a, b, x, y);

  if (x < 0)
    x += b;

  fout << x << "\n";
}
