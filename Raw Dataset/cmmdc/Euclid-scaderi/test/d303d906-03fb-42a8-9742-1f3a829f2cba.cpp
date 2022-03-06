#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int a,b;

int main()

{f>>a>>b;

while(a!=b)

{

    if(a>b)

        a=a-b;

    else

        b=b-a;

}

if(a!=1)

    g <<a;

    else

        g<<0;

    return 0;

}
