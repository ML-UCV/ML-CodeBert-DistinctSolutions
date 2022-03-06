#include <fstream>


using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



long long a, n;



inline long long lgput(long long x, long long y)

{

 long long sol = 1;

 while (y)

 {

  if (y & 1)

   sol = (sol * x) % n;

  x = ((x % n) * (x % n)) % n;

  y >>= 1;

 }

 return sol;

}



inline long long phi(int n)

{

 long long rez = n;

 if (n % 2 == 0)

 {

  rez >>= 1;

  while (n % 2 == 0)

   n >>= 1;

 }

 for (long long i = 3; i * i <= n; i += 2)

 {

  if (n % i == 0)

  {

   rez = rez / i * (i - 1);

   while (n % i == 0)

    n /= i;

  }

 }

 if (n != 1)

  rez = rez / n * (n - 1);

 return rez;

}



int main()

{

 in >> a >> n;

 return out << lgput(a, phi(n) - 1), 0;

}
