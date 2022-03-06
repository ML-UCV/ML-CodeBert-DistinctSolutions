#include <iostream>
#include <fstream>


using namespace std;



typedef unsigned long long ULL;



ULL cmmdc(ULL a, ULL b) {

 unsigned long long rest;

 while(b) {

  rest = a % b;

  a = b;

  b = rest;

 }

 return a;

}



int main() {

 ifstream in("cmmdc.in");



 ULL a, b;

 in >> a;

 in >> b;



 in.close();



 ofstream out("cmmdc.out");



 ULL result = cmmdc(a, b);

 if (result != 1) {

  out << result;

 } else {

  out << 0;

 }





 out.close();



 return 0;

}
