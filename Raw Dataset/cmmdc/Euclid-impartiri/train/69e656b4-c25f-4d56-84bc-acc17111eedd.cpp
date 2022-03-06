#include <iostream>
#include <fstream>


using namespace std;



int cmmdc(int a, int b) {

 int r;



 while (b != 0) {

  r = a % b;

  a = b;

  b = r;

 }



 return a;

}



int main() {

 ifstream fin("cmmdc.in");

 ofstream fout("cmmdc.out");



 unsigned int a, b;



 fin >> a >> b;



 int d = cmmdc(a, b);



 if (d != 1)

  fout << d;

 else

  fout << 0;



 return 0;

}
