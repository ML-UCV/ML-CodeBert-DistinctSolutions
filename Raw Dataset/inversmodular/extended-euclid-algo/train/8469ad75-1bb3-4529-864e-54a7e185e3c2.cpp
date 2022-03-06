#include <iostream>
#include <fstream>


using namespace std;



ifstream fin ( "inversmodular.in" );

ofstream fout ( "inversmodular.out" );



void euclid_extins( int a, int b, int& x, int& y, int& d ) {

 if ( b == 0 ) {

  d = a;

  x = 1;

  y = 0;

  return;

 }

 int xx, yy, q = a / b;

 euclid_extins( b, a % b, xx, yy, d );

 x = yy;

 y = xx - yy * q;

}



int cmmdc( int a, int b ) {

 if ( b == 0 )

  return a;

 return cmmdc( b, a % b );

}



int main() {

    int a, n, x, y, d;

    fin >> a >> n;

    d = cmmdc( a, n );

    euclid_extins( a, n, x, y, d );

    x %= n;

    if ( x < 0 ) {

        x += n;

    }

    fout << x << "\n";

    return 0;

}
