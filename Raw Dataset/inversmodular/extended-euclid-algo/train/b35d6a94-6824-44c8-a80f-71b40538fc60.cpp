#include <bits/stdc++.h>


using namespace std;



int invers_modular(int a, int m)

{

    int y, y0 = 0, y1 = 1;

    int aux = m, r, c;

    while(a!=0)

    {

        r = m%a;

        c = m/a;

        m = a;

        a = r;

        y = y0 - c*y1;

        y0 = y1;

        y1 = y;

    }

    if(y0<0) y0 = aux + y0%aux;

    return y0;

}



int main()

{

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    int a, b;

    fin>>a>>b;

    fout<<invers_modular(a, b);

    fin.close();

    fout.close();

    return 0;

}
