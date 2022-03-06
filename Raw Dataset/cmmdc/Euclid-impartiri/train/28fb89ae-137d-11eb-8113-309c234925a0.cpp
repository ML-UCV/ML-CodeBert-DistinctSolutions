#include <fstream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int cmmdc(int a, int b) {

 if (b == 0)

  return a;

 return cmmdc(b, a % b);



}

int main() {



 int a, b;

 fin >> a >> b;



 int CMMDC = cmmdc(a, b);

 if (CMMDC == 1)

  fout << '0';

 else

  fout << CMMDC;



 return 0;

}
