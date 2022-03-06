#include <fstream>


using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int a,b,c;

int main()

{

    f >> a >> b;

    c = a % b;

    while(c != 0)

    {

        a = b;

        b = c;

        c = a % b;

    }

    if(b == 1)

        b = 0;

    g << b;

    return 0;

}
