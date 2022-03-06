#include <fstream>
#include <iostream>
using namespace std;

ifstream in("cmmdc.in");

ofstream out("cmmdc.out");

int prime, a,b;



int main()

{

    in>>a>>b;

    while(a!=b)

    {

        if(a>b)

            a-=b;

        else

            b-=a;

    }

    if(a==1)

    out<<0;

    else

        out<<a;

    return 0;

}
