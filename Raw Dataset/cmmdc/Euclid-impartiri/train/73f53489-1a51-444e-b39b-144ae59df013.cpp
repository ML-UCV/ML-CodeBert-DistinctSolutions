#include <iostream>
#include <fstream>


int cmmdc(int a, int b) {

 if (b == 0)

  if (a == 1)

   return 0;

  else

   return a;

 else

  return cmmdc(b, a%b);

}



int main()

{

 std::ofstream out("cmmdc.out");

 std::ifstream in("cmmdc.in");

 int a, b;

 in >> a >> b;

 out << cmmdc(a, b);



}
