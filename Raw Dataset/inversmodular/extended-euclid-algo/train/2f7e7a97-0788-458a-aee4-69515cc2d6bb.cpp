#include<bits/stdc++.h>
using namespace std;

int x, X1, X2, cat, rest, rest1, rest2, modulo;

int main()

{

    ifstream f("inversmodular.in");

    ofstream g("inversmodular.out");

    f >> rest1 >> rest2;

    modulo = rest2;

    X1 = 1;

    X2 = 0;

    while(rest1 % rest2 != 0)

    {

        cat = rest1 / rest2;

        rest = rest1 % rest2;

        rest1 = rest2;

        rest2 = rest;

        x = X1 - X2 * cat;

        X1 = X2;

        X2 = x;

    }

    while(x < 0)x = x + modulo;

    g << x;

    return 0;

}
