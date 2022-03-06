#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long a,mod;

void euclid(int a,int b,int &x,int &y){

if(b==0){

   x=1;

   y=0;

   return ;

}

int x0,y0;

euclid(b,a%b,x0,y0);

x=y0;

y=x0-y0*(a/b);

return;

}

int main()

{

   fin>>a>>mod;

   int x,y;

   euclid(a,mod,x,y);

   fout<<(x+mod)%mod;

}
