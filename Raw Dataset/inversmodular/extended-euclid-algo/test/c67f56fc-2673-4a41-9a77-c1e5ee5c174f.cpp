#include <iostream>
#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long x,y,r,r2,aux;

void mad(long long &x, long long &y,long long a,long long b){

  if(!b){

    x=1;

    y=0;

  }

    else{

        mad(x,y,b,a%b);

        aux=x;

        x=y;

        y=aux-y*(a/b);

    }

}

int main(){

    fin>>x>>y;

    mad(r,r2,x,y);

    if(r<=0)

        r=y+(r%y);

    fout<<r;



}
