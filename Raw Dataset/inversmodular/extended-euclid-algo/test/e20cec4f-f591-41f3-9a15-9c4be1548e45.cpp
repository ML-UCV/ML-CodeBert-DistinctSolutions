#include <cstdio>
#include <iostream>

using namespace std;

void euclid(long long a, long long b, long long &X, long long &Y)
{
  if (b == 0) {
    X = 1;
    Y = 0;
    return;
  }
  long long X_, Y_;
  euclid(b, a % b, X_, Y_);



  X = Y_;
  Y = X_ - a/b * Y_;
}

int main()
{
  freopen("inversmodular.in", "r", stdin);
  freopen("inversmodular.out", "w", stdout);

  long long a, MOD, X, Y;
  cin >> a >> MOD;
  euclid(a, MOD, X, Y);
  cout << (X % MOD + MOD) % MOD << "\n";
  return 0;
}
