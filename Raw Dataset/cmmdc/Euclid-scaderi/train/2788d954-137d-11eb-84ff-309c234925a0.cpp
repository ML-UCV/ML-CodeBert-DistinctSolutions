#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmmdc.in");

ofstream out("cmmdc.out");

int main()

{

    int a,b,diva=0,divb=0;

    in >> a;

    in >> b;
          while(a!=b)

    {

        if(a > b)

        {

            a = a - b;

        }

        else

        {

            b = b - a;

        }

    }

    if(a==1) out << "0";

    else out << a;



    return 0;

}
