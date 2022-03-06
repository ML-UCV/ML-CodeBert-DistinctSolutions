#include <fstream>


using namespace std;



ifstream f ("inversmodular.in");

ofstream g ("inversmodular.out");



int a, n;



int phi (int x)

{

  int rez = x;

   for (int i=2; i*i<=x; i++)

   {

       if (x % i == 0)

       {

          while (x % i == 0)

            x /= i;



          rez = (rez / i) * (i-1);

       }

   }



   if (x > 1)

    rez = (rez/x) * (x-1);

  return rez;

}



int Inv_Mod (int x, int mod)

{

   int p = phi(mod) - 1;

   int rez = 1;



    while (p)

    {

        if (p % 2 == 1)

            rez = (1LL * rez * x) % mod;

        x = (1LL * x * x) % mod;

        p /= 2;

    }



  return rez;

}



int main()

{

  f >> a >> n;

  g << Inv_Mod(a, n);

    return 0;

}
