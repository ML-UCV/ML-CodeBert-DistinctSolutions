#include<iostream>
#include<fstream>


using namespace std;



long int a, b, rest;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int main() {



 f >> a >> b;

 while (b != 0) {

  rest = a % b;

  a = b;

  b = rest;

 }

 if (a == 1) {

  g << 0;

 }

 else {

  g << a;

 }



 return 0;

}
