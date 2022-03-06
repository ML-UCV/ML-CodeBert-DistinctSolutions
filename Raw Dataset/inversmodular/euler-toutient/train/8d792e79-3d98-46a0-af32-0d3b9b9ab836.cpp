#include <fstream>


using namespace std;



ifstream fin( "inversmodular.in" );

ofstream fout( "inversmodular.out" );



int phi_gen( int x ){

  int d = 2, cx = x, e;

  while( d * d <= x ){

    e = 0;

    while( !(x % d) ){

      e = 1;

      x /= d;

    }

    if( e == 1 ){

      cx /= d;

      cx *= (d - 1);

    }

    ++d;

  }

  if( x > 1 ){

    cx /= x;

    cx *= (x - 1);

  }

  return cx;

}



int lgput( int x, int y, int n ){

  int p = 1;

  while( y ){

    if( y & 1 )

      p = (1LL * p * x) % n;

    x = (1LL * x * x) % n;

    y >>= 1;

  }

  return p;

}



int main() {

  int a, n, y;

  fin >> a >> n;

  y = phi_gen(n);

  fout << lgput(a, y - 1, n);

  return 0;

}
