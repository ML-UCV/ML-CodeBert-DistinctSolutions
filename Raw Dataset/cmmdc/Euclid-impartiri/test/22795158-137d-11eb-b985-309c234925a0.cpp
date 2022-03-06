#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmmdc.in");

ofstream out("cmmdc.out");

int main()

{

    int a,b,x;

    in>>a;

    in>>b;

    while(b!=0)

    {

        x=a%b;

        a=b;

        b=x;

    }

    if(a!=1)

    out<<a;

    else

        out<<0;

    return 0;

}
