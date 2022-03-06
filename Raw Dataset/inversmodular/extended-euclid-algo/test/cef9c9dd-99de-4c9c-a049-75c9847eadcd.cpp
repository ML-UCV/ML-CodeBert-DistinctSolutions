#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

void EuclidExtins(int a, int b, int &d, int &x, int &y)

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

        EuclidExtins(b, a % b, d, x0, y0);

        x = y0;

        y = x0 - (a / b) * y0;

    }

}

int InversModular(int A, int N)

{

    int X, Y, d;

    EuclidExtins(A, N, d, X, Y);

    X %= N;

    if(X < 0)

        X += N;

    return X;

}

int main()

{ int a,b;

   f>>a>>b;

   g<<InversModular(a,b);

    return 0;

}
