#include <iostream>
#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int a,n;

long long x,y;

void gcd(int a,int b,long long &x,long long &y);

int main() {

    fin>>a>>n;

    gcd(a,n,x,y);

    if (x<=0){

        x=n+x%n;

    }

    fout<<x;

    return 0;

}

void gcd(int a,int b,long long &x,long long &y){

    if (b==0){

        x=1;

        y=0;

        return;

    }

    gcd(b,a%b,x,y);

    int aux=x;

    x=y;

    y=aux-(a/b)*y;

}
