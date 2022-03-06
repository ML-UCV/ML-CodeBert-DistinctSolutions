#include <fstream>
using namespace std;

int main()

{

    ifstream f("cmmdc.in");

    ofstream g("cmmdc.out");

    int a,b;

    f>>a>>b;

    if(a==0 && b!=0)

    {

        g<<b;

    }

    else

    if(b==0 && a!=0)

    {

        g<<a;

    }

    else

    {

        while(a!=b)

        {

            if(a>b)

            {

                a=a-b;

            }

            else

            {

                b=b-a;

            }

        }

        if(a==1)

        {

            g<<0;

        }

        else

        {

            g<<a;

        }

    }

    return 0;

}
