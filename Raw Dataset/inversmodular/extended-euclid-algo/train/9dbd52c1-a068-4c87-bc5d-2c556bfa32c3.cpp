#include <stdio.h>
#include <bits/stdc++.h>



using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

ifstream fin ("inversmodular.in");
ofstream fout ("inversmodular.out");

int ext_gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  int x1, y1;
  int d = ext_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - a/b * y1;

  return d;
}

int main(void) {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int a, n;
  fin >> a >> n;
  int x, y;
  ext_gcd(n, a, x, y);

  y %= n; if (y < 0) { y += n; }
  fout << y << endl;


  return 0;
}
