#include <bits/stdc++.h>


using namespace std;





int main() {

  freopen ("inversmodular.in", "r", stdin);

  freopen ("inversmodular.out", "w", stdout);



  auto get_phi = [&] (int num) {

    int phi = num;

    for (int d = 2; d * d <= num; d++) {

      bool is = 0;

      while (num % d == 0) {

        num /= d;

        is = 1;

      }

      if (is) {

        phi /= d;

        phi *= (d - 1);

      }

    }

    if (num > 1) {

      phi /= num;

      phi *= (num - 1);

    }

    return phi;

  };



  int a, mod;

  cin >> a >> mod;

  int b = get_phi(mod) - 1;

  int sol = 1;



  while (b) {

    if (b & 1) {

      sol = sol * (long long) a % mod;

    }

    a = a * (long long) a % mod;

    b /= 2;

  }

  cout << sol << "\n";





  return 0;

}
