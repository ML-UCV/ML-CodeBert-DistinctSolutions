#include <iostream>
#include <fstream>
using namespace std;



int main ()

{

    ifstream f("cmmdc.in");

    long a,b;

    f>>a>>b;

    ofstream o("cmmdc.out");

    while(a!=b)

        if (a>b)

            a=a-b;

        else

            b=b-a;



    if(a==1)

       a=0;

    o<<a;

    f.close();

    o.close();

}
