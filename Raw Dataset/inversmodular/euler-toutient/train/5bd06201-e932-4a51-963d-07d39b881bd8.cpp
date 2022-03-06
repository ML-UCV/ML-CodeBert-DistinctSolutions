#include<fstream>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



long long n;



long long ridic(long long x, long long p)

{

 if (p == 1)

  return (x %n);

 long long aux = ridic(x, p / 2);



 if (p % 2 == 0)

  return ((aux*aux) % n);

 else

  return ((((aux * aux) % n) *x) % n);

}



long long phi(long long n)

{

 long long rez = n;



 for (long long i = 2; i*i <= n; ++i)

 {

  if (n %i == 0)

  {

   while (n %i == 0)

    n /= i;

   rez -= (rez / i);

  }

 }



 if (n > 1)

  rez -= (rez / n);



 return rez;

}





int main()

{

 long long a;

 f >> a >> n;



 long long ph = phi(n);



 long long inv_m = ridic(a, ph - 1);



 g << inv_m << "\n";



 return 0;

}
