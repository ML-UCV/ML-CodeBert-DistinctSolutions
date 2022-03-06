#include <fstream>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void euclid(int a, int b, int* d, int* x, int* y);



int main()

{

 int a, n;



 fin >> a >> n;



 int x, y, d;



 euclid(a, n, &d, &x, &y);



 if (x < 0)

 {

  x = (n + x) % n;

 }



 fout << x;



 fin.close();

 fout.close();

 return 0;

}



void euclid(int a, int b, int* d, int* x, int* y)

{

 if (b == 0)

 {

  *d = a;

  *x = 1;

  *y = 0;

 }

 else

 {

  int x0, y0;



  euclid(b, a % b, d, &x0, &y0);



  *x = y0;

  *y = x0 - (a / b) * y0;

 }

}
