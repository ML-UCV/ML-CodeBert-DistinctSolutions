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

        int rest;

        if(a<b)

        {

            swap(a,b);

        }

        while(a%b)

        {

            rest=a%b;

            a=b;

            b=rest;

        }

        if(b==1)

        {

            g<<0;

        }

        else

        {

            g<<b;

        }

    }

    return 0;

}
