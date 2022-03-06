#include <iostream>
#include <fstream>


using namespace std;



ifstream in("cmmdc.in");

ofstream out("cmmdc.out");



int euclid(int a, int b)

{

  if (!b)

   return a;

 return euclid(b, a % b);

}



int main()

{

 int x, y;

  in >> x >> y;

  if (euclid(x, y) == 1)

   out << 0;

  else

   out << euclid(x, y);



 return 0;



}
