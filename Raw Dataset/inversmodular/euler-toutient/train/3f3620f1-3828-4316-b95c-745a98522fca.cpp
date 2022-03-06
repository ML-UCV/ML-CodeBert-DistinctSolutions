#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int InvMod(int a, int b)

{

    long long x1 = 1, x2 = 0, aux, q, auxb = b;



    while(b)

    {

        q = a / b;

        aux = b;

        b = a - q * b;

        a = aux;

        aux = x2;

        x2 = x1 - q * x2;

        x1 = aux;

    }



    if(x1 < 0)

    {

        x1 += auxb;

    }



    return x1;

}



int main()

{

    int a, b;



    fin >> a >> b;



    fout << InvMod(a, b);



    fin.close();

    fout.close();

    return 0;

}
