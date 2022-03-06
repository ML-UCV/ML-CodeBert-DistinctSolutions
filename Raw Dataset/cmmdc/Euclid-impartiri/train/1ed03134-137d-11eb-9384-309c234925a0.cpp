#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");

int main(){

  unsigned int a,b,r;

   fin>>a>>b;

  r=a%b;

   while(r){

        r = a % b;

        a = b;

        b = r;}

   if(a==1)fout<<0;

   else fout<<a;

   fin.close();fout.close();

    return 0;

}
