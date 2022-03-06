#include <iostream>
#include <fstream>




using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long n,a;

void euclid(int a,int b,long long &x,long long &y){

    if(b==0){

        x=1,y=0;

    }

    else{

        euclid(b,a%b,x,y);

        long long auxx=x;

        x=y;

        y=auxx-y*(a/b);

    }

}

int main(){

    long long x=0,y=0;

    fin>>a>>n;

    euclid(a,n,x,y);

    if(x<=0){

        x=n+x%n;

    }

    fout<<x;

    return 0;

}
