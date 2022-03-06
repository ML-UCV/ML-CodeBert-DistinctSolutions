#include<fstream>
using namespace std;

ifstream f("inversmodular.in"); ofstream g("inversmodular.out");



int A, N;

void gcd(long long &x, long long &y, int a, int b)

{ if (!b){ x = 1; y = 0; }

    else

    { gcd(x, y, b, a % b);

        long long aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}

int main()

{ long long invers=0,ins;

    f>>A>>N;

    gcd(invers,ins,A,N);

    if (invers <= 0) invers = N + invers % N;

    g<<invers;

}
