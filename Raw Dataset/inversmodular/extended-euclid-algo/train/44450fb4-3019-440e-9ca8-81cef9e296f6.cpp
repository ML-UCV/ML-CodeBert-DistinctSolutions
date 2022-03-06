#include <fstream>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



void EE(int a, int b, int &d, int &x, int &y)

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

        EE(b, a % b, d, x0, y0);

        x = y0;

        y = x0 - (a / b) * y0;

    }

}



int inversModular(int A, int N)

{

    int X, Y, d;

    EE(A, N, d, X, Y);

    X %= N;

    if(X < 0)

        X += N;

    return X;

}



int main()

{

    int A, N;

    f >> A >> N;

    g << inversModular(A, N);

    return 0;

}
