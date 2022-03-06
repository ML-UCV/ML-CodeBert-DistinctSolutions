#include <iostream>
#include <fstream>
using namespace std;



int cmmdc(int a, int b)

{

    int t;

    while (b != 0)

    {

        t = b;

        b = a % b;

        a = t;

    }

    return a;

}



ifstream in("cmmdc.in");

ofstream out("cmmdc.out");



int main()

{

    int a,b;

    in>>a>>b;

    if(a==b)

        out<<a;

    else if(a%b==0)

            out<<b;

            else if(b % a == 0)

                    out<<a;

                else if(cmmdc(a, b) == 1)

                        out<<'0';

                        else out<<cmmdc(a, b);

    return 0;

}
