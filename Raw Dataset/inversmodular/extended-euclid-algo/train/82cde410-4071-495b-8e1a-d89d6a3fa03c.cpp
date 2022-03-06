#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int a,n;

void invmd(long long &inv,long long &ins,int a,int n)

{

    if(n==0)

    {

        inv=1;

        ins=0;

    }

    else{

        invmd(inv,ins,n,a%n);

        long long aux=inv;

        inv=ins;

        ins=aux-ins*(a/n);

    }

}

int main()

{

    fin>>a>>n;

    long long inv=0,ins;

    invmd(inv,ins,a,n);

    if(inv<=0)

        inv=n+inv%n;

    fout<<inv;

    return 0;

}
