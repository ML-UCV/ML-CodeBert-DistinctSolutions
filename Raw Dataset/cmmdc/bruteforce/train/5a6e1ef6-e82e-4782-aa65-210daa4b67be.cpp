#include<iostream>
#include<fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int main()

{ int a,b,cmmdc,n,i;

f>>a>>b;

if(a<b)

    n=b;

else

    n=a;

for (i=1;i<=n;i++)

if(a%i==0 && b%i==0)

cmmdc=i;

if(cmmdc<=30000 && cmmdc!=1)

g<<cmmdc;

else if(cmmdc>30000)

    g<<"Prea mare numarul";

else if(cmmdc==1)

    g<<0;

return 0;}
