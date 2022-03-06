#include <fstream>
using namespace std;



ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int CMMDC(int a, int b)

{

 int c;

 while (b)

 {

  c = a % b;

  a = b;

  b = c;

 }

 return a;

}



int main()

{

 int a, b;

 f >> a >> b;

 if (CMMDC(a, b) == 1)

  g << 0;

 else

  g << CMMDC(a, b);

 return 0;

}
