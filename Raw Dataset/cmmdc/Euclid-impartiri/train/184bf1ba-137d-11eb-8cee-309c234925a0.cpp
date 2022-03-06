#include<iostream>
#include<fstream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int main() {



 int cmmdc_a, cmmdc_b, a, b,max;



 fin >> a >> b;





 if (a > b) {

  max = a;

 }

 else {

  max = b;

 }



 do {



  cmmdc_a = a % max;

  cmmdc_b = b % max;



  max--;



 } while (cmmdc_a!=0 || cmmdc_b!=0);





 max++;



 if (max == 1) {

  max--;

 }



 fout << max;



 cin.get();

 return 0;

}
