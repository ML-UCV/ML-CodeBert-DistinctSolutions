#include <iostream>
#include <fstream>


using namespace std;

ifstream fin ( "inversmodular.in" );
ofstream fout ( "inversmodular.out" );


int phi ( int n ){

   int euler = 1;
   int e = 0;

   while ( n % 2 == 0 ){
      n /= 2;
      euler *= 2;
      e ++;
   }

   if ( e )
     euler /= 2;

   int d = 3;
   while ( d * d <= n ){

      e = 0;
      while ( n % d == 0 ){
         e ++;
         n /= d;
         euler *= d;
      }

      if ( e )
        euler = euler / d * ( d - 1 );

      d += 2;
   }

   if ( n > 1 )
     euler *= ( n - 1 );
   return euler;
}

int log_exp ( long long x, int p, int mod ) {

   long long rez = 1;

   while ( p > 0 ){

      if ( p % 2 == 0 )
         x = x * x % mod, p /= 2;
      else
        rez = rez * x % mod, p --;

   }
   return rez;
}

int main()

{


   int a, n;



   fin >> a >> n;

   fout << log_exp ( a, phi ( n ) - 1, n );

    return 0;

}
