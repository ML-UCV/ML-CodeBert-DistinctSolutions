#include <iostream>
#include <fstream>
using namespace std;



int main()

{

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int a,b,A,B;

f>>a>>b;

A=a;

B=b;

while(A!=B){

if(A>B) A=A-B;

else B=B-A;

}

if(A>1) g<<A;

else if(A==1) g<<0;



    return 0;

}
