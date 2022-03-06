#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void euclid_e(int a, int b, long long &x, long long &y)

{

    if (b == 0)

    {

        x = 1;

        y = 0;

        return;

    }

    long long xx, yy, q = a / b;

    euclid_e(b, a % b, xx, yy);

    x = yy;

    y = xx - yy * q;

}





int main()

{

    int a, n;

    long long x = 0, y;

    fin >> a >> n;

    euclid_e(a, n, x, y);

    x %= n;

    if (x < 0)

        x += n;

    fout << x;

    return 0;

}
