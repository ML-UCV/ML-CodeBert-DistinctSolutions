#include <iostream>
#include <fstream>
using namespace std;



int main() {

 int a, b;

 ifstream f("cmmdc.in");

 ofstream g("cmmdc.out");

 f >> a;

 f >> b;





 while (a != b)

 {

  if (a > b)

   a = a - b;

  else

   b = b - a;

 }

 if (a == 1) g << 0;

 else g << a;



}
