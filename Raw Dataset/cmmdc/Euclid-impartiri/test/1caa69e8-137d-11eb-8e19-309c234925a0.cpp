#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int main()

{

    int a,b,r;

    f>>a>>b;

    while(b)

    {

        r=a%b;

        a=b;

        b=r;

    }

    g<<(a==1? 0 : a);

    f.close();

    g.close();

    return 0;
}
