#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

void euclid(int a, int b, int &d, int &x, int &y)

{

    if(b == 0)

    {

        x = 1;

        y = 0;

        d = a;

    }

    else

    {

        int x0, y0;

        euclid(b, a % b, d, x0, y0);

        x = y0;

        y = x0 - (a / b) * y0;

    }

}

int invmod(int a, int n)

{

    int x, y, d;

    euclid(a, n, d, x, y);

    x %= n;

    if(x < 0)

        x += n;

    return x;

}

int main()

{

    int a, n;

    f >> a >> n;

    g << invmod(a, n);

    return 0;

}
