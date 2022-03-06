#include <iostream>
#include <fstream>
using namespace std;

int main ()

{int a,b,r;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

f>>a;

f>>b;

do{r=a%b;

a=b;

b=r;}while (b>0);

if(a==1) g<<0;

else g<<a;

}
