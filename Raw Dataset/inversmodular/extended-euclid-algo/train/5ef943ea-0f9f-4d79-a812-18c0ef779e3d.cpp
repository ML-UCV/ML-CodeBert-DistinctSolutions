#include <iostream>
#include <fstream>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int modInv(int a, int b)

{

    long long r, x1=1, x2=0, q, aux, auxb = b;



    while(b > 0)

    {

        q = a/b;

        aux = a;

        a = b;

        b = aux - q * b;

        aux = x1;

        x1 = x2;

        x2 = aux - q * x2;

    }

    if(x1 < 0)

    {

        x1 += auxb;

    }

    return x1;

}



int main()

{

    int a, n;



    fin>>a>>n;



    fout<<modInv(a, n);



    fin.close();

    fout.close();

    return 0;

}
