#include <fstream>


using namespace std;



void gcd(int a, int b, int& x, int& y) {

 if (!b) {

  x = 1;

  y = 0;

 } else {

  int x0, y0;

  gcd(b, a % b, x0, y0);

  x = y0;

  y = x0 - a / b * y0;

 }

}



int main() {

 ifstream fin("inversmodular.in");

 ofstream fout("inversmodular.out");



 int A, N;



 fin >> A >> N;



 int inv, y;



 gcd(A, N, inv, y);



 while (inv < 0)

  inv += N;



 fout << inv;



 return 0;

}
