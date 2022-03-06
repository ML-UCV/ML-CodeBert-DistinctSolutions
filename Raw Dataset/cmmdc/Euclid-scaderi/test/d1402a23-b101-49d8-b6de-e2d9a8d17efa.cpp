#include <iostream>
#include<fstream>
using namespace std;
ifstream in("cmmdc.in");
ofstream out("cmmdc.out");

int main()
{ int a,b,aux=0;
in>>a>>b;
 while(b!=a){
  if(a>b)
   a-=b;
  if(b>a)
  b-=a;
 }

 if(a==1){
  out<<"0";
 }else{
  out<<a;
}

}
