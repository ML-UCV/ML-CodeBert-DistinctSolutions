#include <iostream>
#include <fstream>


std::ifstream f("cmmdc.in");

std::ofstream g("cmmdc.out");



int main()

{

 int a, b;

 f >> a >> b;

 while (a != b && a>0 && b>0)

  if (a > b)

   a = a - b;

  else

   b = b - a;

 if (a == 1)

  g << 0;

 else

        g << a;

 f.close();

 g.close();

 return 0;

}
