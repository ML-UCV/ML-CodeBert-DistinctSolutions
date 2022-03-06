#include <fstream>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int a, n;

int x, y;



void ee(int a, int n, int &x, int &y) {

 if(!n) {

  x=1;

  y=0;

  return;

 }

 int xp, yp;

 ee(n, a%n, xp, yp);

 x=yp;

 y=xp-(a/n)*yp;

}



int main() {

 f>>a>>n;



 ee(a, n, x, y);



 while(x<0)

  x+=n;



 g<<x;



 f.close();

 g.close();

 return 0;

}
