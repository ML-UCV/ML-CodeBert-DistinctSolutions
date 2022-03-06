#include <fstream>


using namespace std;



void gcd (long a, long b, long *d, long *x, long *y) {

    if (b == 0) {

        *d = a;

        *x = 1;

        *y = 0;

    }

    else {

        long x0, y0;

        gcd (b, a%b, d, &x0, &y0);

        *x = y0;

        *y = x0 - (a/b) * y0;

    }

}

int main()

{

    ifstream f ("inversmodular.in");

    ofstream g ("inversmodular.out");

    long a, n, d, x, y;

    f >> a >> n;

    gcd (a, n, &d, &x, &y);

    while (x < 0)

        x += n;

    g << x;

    return 0;

}
