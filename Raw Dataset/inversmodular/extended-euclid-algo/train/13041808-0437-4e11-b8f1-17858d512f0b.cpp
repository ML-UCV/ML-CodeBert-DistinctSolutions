#include <fstream>






using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



inline int gcdExtended(int a, int b, int &x, int &y)

{

    if(b == 0)

    {

        x = 1;

        y = 0;

        return a;

    }

    int x0, y0, d = gcdExtended(b, a%b, x0, y0);

    x = y0;

    y = x0 - (a / b) * y0;

    return d;

}



int main()

{

    int a, n, x, y;

    fin >> a >> n;

    int d = gcdExtended(a, n, x, y);

        if(1 % d == 0)

        {

            x = x * (1 / d);

            if(x < 0)

                fout << x + n;

            else

                fout << x;

        }

        else

            fout << "0\n";

    return 0;

}
