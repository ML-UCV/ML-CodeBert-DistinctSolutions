#include <fstream>


using namespace std;



int main() {

  ifstream cin ("inversmodular.in");

  ofstream cout ("inversmodular.out");

  long long a, n, i, cn, nr, put;

  cin >> a >> n;

  cn = nr = n;

  i = 2;

  while (i * i <= cn) {

    if (cn % i == 0) {

      nr = nr / i * (i - 1);

      while (cn % i == 0)

        cn /= i;

    }

    i++;

  }

  if (cn > 1)

    nr = nr / cn * (cn - 1);

  nr--;

  put = 1;

  while (nr) {

    if (nr % 2)

      put = (put * a) % n;

    nr /= 2;

    a = (a * a) % n;

  }

  cout << put;

  return 0;

}
