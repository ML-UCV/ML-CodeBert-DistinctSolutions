#include <iostream>
#include<fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int main()

{

int a,b;

f>>a>>b;

while(a!=b){

    if(a>b)a=a-b;

    else b=b-a;

}

if (a==1)g<<0;

else g<<a;

}
