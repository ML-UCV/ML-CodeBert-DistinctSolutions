#include <iostream>
#include <fstream>


using namespace std;



int cmmdc(int a, int b)

{ int r;

  while (b!=0)

  { r=a%b;

    a=b;

    b=r;

  }

 return a;

}



int main()

{ int a,b;

   ifstream f("cmmdc.in");

   ofstream g("cmmdc.out");

   f >> a >> b;

   if (cmmdc(a,b)==1) g << "0";

    else g << cmmdc(a,b);



}
