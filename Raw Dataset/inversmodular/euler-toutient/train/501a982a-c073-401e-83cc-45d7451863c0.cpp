#include <fstream>


using namespace std;



int phi(int n) {

 int rez = n;



 for (int i = 2;i * i <= n;i ++) {

  if (n % i == 0) {



   while (n % i == 0) {

    n /= i;

   }



   rez = rez / i * (i - 1);

  }

 }



 if (n != 1)

  rez = rez / n * (n - 1);

 return rez;

}



long long ridicare_la_putere(int x, int n, int exp) {

 if (exp == 0)

  return 1;

 if (exp % 2 == 0)

  return ridicare_la_putere(1LL * x * x % n, n, exp / 2) % n;

 return 1LL * x * ridicare_la_putere(1LL * x * x % n, n, (exp - 1) / 2) % n;

}



int main() {

 ifstream fin("inversmodular.in");

 ofstream fout("inversmodular.out");



 int A, n;

 fin >> A >> n;



 int exponent = phi(n);





 fout << ridicare_la_putere(A, n, exponent - 1);



 return 0;

}
