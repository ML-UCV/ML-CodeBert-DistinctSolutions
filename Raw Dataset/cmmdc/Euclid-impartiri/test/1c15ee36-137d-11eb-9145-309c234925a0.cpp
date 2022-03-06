#include <fstream>
#include <iostream>
using namespace std;



ifstream fin("cmmdc.in");

ofstream fon("cmmdc.out");

int main(){

int a,b,r;

fin>>a>>b;

while(b!=0){

 r = a % b;

 a = b;

 b = r;}

if(a!=1)

fon<<a;

else

fon<<"0";

return 0;

}
