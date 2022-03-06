#include <iostream>
#include <fstream>
using namespace std;



int main() {

 ifstream in("cmmdc.in");

 ofstream out("cmmdc.out");



 int a, b;

 in >> a >> b;

 while (a != b) {

  if (a > b)

   a = a - b;

  else

   b = b - a;

 }

 if (a == 1)

  a = 0;

 out << a;

 return 0;



}
