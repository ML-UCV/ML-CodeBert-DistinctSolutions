#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int euclext(int a, int b, int c, int &x, int &y)

{

    int q[50], x0, y0, r, pos = 0;

    while(b)

    {

        q[++pos] = a / b;

        r = a % b;

        a = b;

        b = r;

    }

    if(c % a) {x=y=0;return 0;}

    x0 = c / a;

    y0 = 0;

    while(pos)

    {

        x = y0;

        y = x0 - q[pos--] * y0;

        x0 = x;

        y0 = y;

    }

    return 1;

}



int main()

{

    int a, b, x, y;

    fin >> a >> b;

    euclext(a, b, 1, x, y);

    x=((long long)b+x%b)%b;

    fout << x;

    return 0;

}
