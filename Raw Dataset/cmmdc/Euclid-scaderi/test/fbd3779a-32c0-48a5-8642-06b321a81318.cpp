#include <fstream>


using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

long long a,b;

int main()

{

    f>>a>>b;

    while (a!=b)

    {

        if (a<b)

            b=b-a;

        else a=a-b;

    }

    if (a==1)

        g<<0;

        else

            g<<a%30000;



    return 0;

}
