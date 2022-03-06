#include <fstream>
using namespace std;



int main(){

 int a,b,d=0;

 ifstream fileIn;

 fileIn.open("cmmdc.in");

 ofstream fileOut;

 fileOut.open("cmmdc.out");

 if(fileIn.is_open()){

  fileIn>>a;

  fileIn>>b;

 }

 for(int i=2; i<=(a<b?a:b); i++){

  if(a%i == 0 && b%i==0 && d<i){

   d=i;

  }

 }

 fileOut<<d;

 fileIn.close();

 fileOut.close();



}
