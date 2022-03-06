#include <iostream>
#include <fstream>


using namespace std;



int main()

{

    int a,b,r;

    ifstream f("cmmdc.in");

    ofstream g("cmmdc.out");

    f>>a>>b;



    while(b!=0)

    {

        r = a%b;

        a = b;

        b = r;

    }

    if(a==1)

        g<<0;

    else

        g<<a;



    f.close();

    g.close();



    return 0;

}
