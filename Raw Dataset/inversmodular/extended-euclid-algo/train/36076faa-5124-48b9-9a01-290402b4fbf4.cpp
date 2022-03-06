#include <fstream>


using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");





void euclid_e( int a, int b, int& x, int& y, int& d ) {

 if ( b == 0 )

    {

  d = a;

  x = 1;

  y = 0;

  return;

 }

 int xx, yy, q = a / b;

 euclid_e( b, a % b, xx, yy, d );

 x = yy;

 y = xx - yy * q;

}



int main()

{

    int a, n, x, y, d;

    in >> a >> n;

    euclid_e(a, n, x, y, d);

    x %= n;

    if (x < 0)

    {

        x += n;

    }

    out << x;

    in.close();

    out.close();

    return 0;

}
