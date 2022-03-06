#include <iostream>
#include <fstream>
using namespace std;



int main()

{

int a,b,z,x,i;



    ifstream f("cmmdc.in");

    ofstream g("cmmdc.out");

    f>>a;

    f>>b;

    x=0;

    z=0;



    for(i=2;i<=a;i++)

    {

        if (a%i==0&&b%i==0)

        {

            x=i;

        }

        if (x>z)

        {

            z=x;

        }

    }



    g<<z;



    return 0;

}
