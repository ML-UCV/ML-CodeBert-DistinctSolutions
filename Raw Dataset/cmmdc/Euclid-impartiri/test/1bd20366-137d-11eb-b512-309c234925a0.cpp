#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int64_t a, b, cmmdc(int64_t, int64_t);

int main()

{

    f >> a >> b;

    if(cmmdc(a, b) == 1)

        g << 0;

    else

        g << cmmdc(a, b);

    return 0;

}

int64_t cmmdc(int64_t x, int64_t y)

{

    if(x % y == 0)

        return y;

    return cmmdc(y, x % y);

}
