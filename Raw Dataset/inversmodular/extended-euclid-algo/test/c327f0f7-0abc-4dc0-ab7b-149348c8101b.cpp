#include <iostream>
#include <fstream>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int euclid(int a, int b, int &x, int &y)

{

    if (b == 0)

    {

        x = 1;

        y = 0;

        return a;

    }

    int x0, y0;

    int rez = euclid(b, a%b, x0, y0);

    x = y0;

    y = x0 - (a/b) * y0;

    return rez;

}



int main()

{

    int a, n;

    int x, y;

    f >> a >> n;

    euclid(a, n, x, y);

    while (x < 0)

        x += n;

    g << x;

    return 0;

}
