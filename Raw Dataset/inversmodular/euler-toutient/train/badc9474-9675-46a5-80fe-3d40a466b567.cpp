#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int n,pr;

int MOD,invers,mod;



void exp(long long int nr,long long int ad,long long int x)

 {

  if(nr!=pr)

  {

  if(nr+ad<=pr) {

                 invers=(invers*x)%MOD;

                 x=(x*x)%MOD;

                 nr+=ad;

                 ad*=2;

                 exp(nr,ad,x);

                }

  else exp(nr,1,n);

  }

 }

int main()

{

f>>n>>mod;

MOD=mod;

pr=mod;

int d=3;

if(mod%2==0)

 {

  pr=pr/2;

  while(mod%2==0)

    mod/=2;

 }

while(d*d<=mod&&mod!=1)

  {

   if(mod%d!=0) d+=2;

   else

    {

     pr=pr/d*(d-1);

     while(mod%d==0)

       mod/=d;

    }

  }

if(mod!=1) pr=pr/mod*(mod-1);

pr--;

invers=n;

if(pr==0) g<<"1";

else

{

exp(1,1,n);

g<<invers;

}

}
