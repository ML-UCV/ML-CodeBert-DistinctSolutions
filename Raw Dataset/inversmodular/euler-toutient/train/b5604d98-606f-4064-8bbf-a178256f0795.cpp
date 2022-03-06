#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



typedef long long ll;



ll a, b;



ll phi(ll n) {

  ll ans, d;

  ans = n;

  d = 2;

  while (d * d <= n) {

    if (n % d == 0) {

      while (n % d == 0) {

        n /= d;

      }

      ans = ans / d * (d - 1);

    }

    d += 1 + (d % 2);

  }

  if (n != 1) {

    ans = ans / n * (n - 1);

  }

  return ans;

}



ll lgpow(ll base, ll exp) {

  ll ans;

  ans = 1;

  while (exp > 0) {

    if (exp % 2 > 0) {

      ans = (1LL * ans * base) % b;

    }

    base = (1LL * base * base) % b;

    exp >>= 1;

  }

  return ans;

}



int main() {

  fin >> a >> b;

  fout << lgpow(a, phi(b) - 1);

  return 0;

}
