#include <iostream>
#include <fstream>
using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int gcd(int a, int b, int &x, int &y)

{

    if(b == 0)

        x = 1, y = 0;

    else

    {

        gcd(b, a % b, x, y);

        int aux = y;

        y = x - (a / b) * y;

        x = aux;

    }

}



int a, n, inv, ins;



int main()

{

    f >> a >> n;

    gcd(a, n, inv, ins);

    if(inv <= 0)

        inv = n + inv % n;

    g << inv << "\n";

    return 0;

}
