#include <fstream>
using namespace std;

ifstream fi("cmmdc.in");

ofstream fo("cmmdc.out");



int main()

{

    int a, b, r;

    fi>>a>>b;

    while (b != 0)

    {

        r = a%b;

        a = b;

        b = r;

    }

    if (a == 1)

        fo<<0;

    else

        fo<<a;

    fi.close();

    fo.close();

}
