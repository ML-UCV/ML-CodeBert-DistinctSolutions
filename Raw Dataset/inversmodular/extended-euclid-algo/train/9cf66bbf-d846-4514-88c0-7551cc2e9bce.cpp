#include <bits/stdc++.h>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int n, k;

int inv, ins;



void invers_modular(int a, int b, int &x, int &y)

{

    if(!b)

    {

        x = 1;

        y = 0;

    }

    else

    {

        invers_modular(b, a % b, x, y);

        int aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}



int main()

{

    f>>n>>k;

    invers_modular(n, k, inv, ins);

    while(inv <= 0)

        inv = k + inv % k;

    g<<inv<<'\n';

    g.close();

    return 0;

}
