#include <iostream>
#include <fstream>


using namespace std;

ifstream r("inversmodular.in");

ofstream w("inversmodular.out");

int A, N;

void euclid(long long &x, long long &y, int a, int b)

{

    if (!b)

        x = 1, y = 0;

    else

    {

        euclid(x, y, b, a % b);

        long long aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}

int main()

{

    long long inv=0, ins;

    r>>A>>N;

    euclid(inv, ins, A, N);

    if (inv <= 0)

        inv = N + inv % N;

    w<<inv;

    return 0;

}
