#include <bits/stdc++.h>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int a, b, c, x, y, d, n;

int cmmdc(int a, int b, int &x, int &y)

{

    if(b == 0)

    {

        x = 1, y = 0;

        return a;

    }

    int x0, y0, d;

    d = cmmdc(b, a%b, x0, y0);



    x = y0;

    y = x0-(a/b)*y0;

    return d;

}



int main()

{

    fin >> a >> b;

    d = cmmdc(a, b, x, y);



    while(x < 0)

        x += b;

    fout << x;

    return 0;

}
