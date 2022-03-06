#include <iostream>
#include <fstream>






using namespace std;

ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



void invers_modular(long long &x, long long &y, int a, int b)

{

     if (!b)

         x = 1, y = 0;

     else

     {

         invers_modular(x, y, b, a % b);

         long long aux = x;

         x = y;

         y = aux - y * (a / b);

     }

}

int a,n;

int main()

{

    long long inv=0,ins;

    in>>a>>n;

    invers_modular(inv,ins,a,n);

    if(inv <= 0)

        inv=n+inv%n;

    out<<inv;

    return 0;

}
