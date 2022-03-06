#include <iostream>
#include <fstream>
using namespace std;

int GCD(int a , int b){

  if (!b)

    return a;

  return GCD(b,a%b);

}

int main() {

  int a, b;

  bool prime = false;

  ifstream fin("cmmdc.in");

  ofstream fout("cmmdc.out");

  fin >> a >> b;

  if ( GCD(a, b) != 1 ) {

    fout << GCD(a, b);

    prime = true;

  }

  if ( prime == false ) {

    fout << 0;

  }

  return 0;

}
