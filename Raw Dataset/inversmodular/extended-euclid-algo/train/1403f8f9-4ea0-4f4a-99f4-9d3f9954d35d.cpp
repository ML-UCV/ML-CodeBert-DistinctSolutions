#include <iostream>
#include <fstream>


using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



void inv_mod(long long &inv, long long &ins, int a, int b) {

  if(b == 0) {

    inv = 1;

    ins = 0;

  } else {

    inv_mod(inv, ins, b, a % b);

    swap(inv, ins);



    ins -= inv * (a / b);

  }

}



int main()

{

  int a, n;

  long long inv, ins;



  in >> a >> n;



  inv_mod(inv, ins, a, n);



  inv = (inv + n) % n;



  out << inv << '\n';



  in.close();

  out.close();



  return 0;

}
