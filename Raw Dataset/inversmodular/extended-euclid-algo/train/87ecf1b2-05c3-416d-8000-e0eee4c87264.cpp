#include <iostream>
#include <fstream>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int modinv(int a, int b)

{

    long long auxb = b, q, x1 = 1, x2 = 0, aux;



    while(b)

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

    int x, y;

    fin>>x>>y;

    fout<<modinv(x, y);

    fin.close();

    fout.close();

    return 0;

}
