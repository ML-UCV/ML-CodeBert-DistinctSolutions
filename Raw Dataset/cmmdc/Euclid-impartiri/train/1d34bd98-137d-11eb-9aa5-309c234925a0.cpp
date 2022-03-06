#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int main()

{

    int a, b;

    f>>a>>b;

    while(b!=0)

    {

        int r=a%b;

        a=b;

        b=r;



    }

    if(a!=1)

        g<<a;

    else

        g<<0;

    return 0;

}
