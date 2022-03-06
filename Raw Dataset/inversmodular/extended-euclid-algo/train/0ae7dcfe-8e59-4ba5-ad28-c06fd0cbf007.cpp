#include <fstream>


using namespace std;

ifstream in ("inversmodular.in");

ofstream out ("inversmodular.out");



long long int gcd(long long int a, long long int b, long long int &x, long long int &y) {

 if (a == 0) {

  x = 0;

  y = 1;

  return b;

 }



 long long int x1, y1, d;

 d = gcd(b % a, a, x1, y1);



 x = y1 - (b / a) * x1;

 y = x1;



 return d;

}



int main()

{

    long long int x, y, a, n, invmod;



    in>> a >> n ;



    invmod = gcd(a, n, x, y);



    while(x < 0)

        x += n;

    out<< x ;

    return 0;

}
