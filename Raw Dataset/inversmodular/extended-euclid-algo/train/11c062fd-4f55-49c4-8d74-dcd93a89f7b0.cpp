#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int a,n;

void invers(long long &x,long long &y,int a,int b)

{

    if(b==0)

    {

        x=1;

        y=0;

    }

    else{

        invers(x,y,b,a%b);

        long long aux=x;

        x=y;

        y=aux-y*(a/b);

    }

}

int main()

{

   fin>>a>>n;

   long long inv=0,ins;

   invers(inv,ins,a,n);

   if(inv<=0)

    inv=n+inv%n;

   fout<<inv;

    return 0;

}
