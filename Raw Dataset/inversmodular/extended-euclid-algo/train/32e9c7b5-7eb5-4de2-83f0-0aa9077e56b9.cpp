#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



void euclid(int a, int b, int* x, int* y)

{

 if (b == 0)

 {

  *x = 1;

  *y = 0;

 }

 else

 {

  int x0, y0;

  euclid(b, a % b, &x0, &y0);

  * x = y0;

  *y = x0 - a / b * y0;

 }







}





int main()

{

 int a, b, d, x, y;



 f >> a >> b;

  d = 0;

 euclid(a, b, &x, &y);

 if (x < 0)

 {

  int aux = -x/b;

  x = x + aux * b;

  if (x < 0) x += b;

 }

 g << x;
 return 0;



}
