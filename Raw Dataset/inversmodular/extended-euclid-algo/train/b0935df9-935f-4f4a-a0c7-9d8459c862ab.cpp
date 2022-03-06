#include <stdio.h>
#include <bits/stdc++.h>





using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ifstream fin ("inversmodular.in");
ofstream fout ("inversmodular.out");

void ext_gcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  int x0, y0;
  ext_gcd(b, a % b, x0, y0);
  x = y0;
  y = x0 - (a / b) * y0;
}

int main(void) {
  int a,n;
  fin >> a >> n;
  int x, y;
  ext_gcd(a, n, x, y);
  x = x % n;
  if (x < 0) {
    x += n;
  }
  fout << x << endl;

  return 0;
}
