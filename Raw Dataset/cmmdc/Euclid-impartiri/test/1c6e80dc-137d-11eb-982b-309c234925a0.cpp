#include <fstream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int cmmdc(int a, int b) {

 if (b == 0)

  return (a == 1) ? 0 : a;

 return cmmdc(b, a % b);

}



int main() {

 int a, b;

 fin >> a >> b;

 fout << cmmdc(a, b);



 return 0;

}
