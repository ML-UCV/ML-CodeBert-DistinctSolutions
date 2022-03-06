#include <iostream>
#include <fstream>


using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



void euclid(int a, int b, int *d, int *x, int *y){

  if( b == 0 ){

    *d = a;

    *x = 1;

    *y = 0;

  }

  else {

    int x0, y0;

    euclid( b, a % b, d, &x0, &y0 );

    *x = y0;

    *y = x0 - ( a / b ) * y0;

  }

}



int main()

{

    int n, x, y, a, d;

    in>>a>>n;

    euclid( a, n, &d, &x, &y );

    if( x < 0 )

      x = n + x % n;

    out<<x;

    return 0;

}
