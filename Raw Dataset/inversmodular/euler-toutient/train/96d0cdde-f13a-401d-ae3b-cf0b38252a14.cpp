#include <fstream>


using namespace std;



ifstream cin("inversmodular.in");

ofstream cout("inversmodular.out");

int main() {

  long long n, a, phi, cn, ans, d;

  cin >> a >> n;

  cn = n;

  phi = n;

  d = 2;

  while ( d * d <= n ) {

    if ( n % d == 0 ) {

      phi = phi / d * ( d - 1 );

      while ( n % d == 0 )

        n /= d;

    }

    d++;

  }

  if ( n > 1 )

    phi = phi / n * ( n - 1 );

  phi--;

  ans = 1;

  while ( phi > 0 ) {

    if ( phi % 2 != 0 )

      ans = ans * a % cn;

    phi /= 2;

    a = a * a % cn;

  }

  cout << ans;

  return 0;

}
