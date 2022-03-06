#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int main(void)

{

 int a,b;

 f>>a>>b;

 while(a!=b)

 {

  if(a>b)

   a-=b;

  else

   b-=a;

 }

 if(a==1 || b==1)

  g<<0;

 else

  g<<a;



 return 0;

}
