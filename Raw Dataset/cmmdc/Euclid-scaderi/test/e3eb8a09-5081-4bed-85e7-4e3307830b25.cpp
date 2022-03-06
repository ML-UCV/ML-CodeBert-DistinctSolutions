#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmmdc.in");

ofstream out("cmmdc.out");



int main()

{

    long a;

    long b;

    in >> a;

    in >> b;

    while(a != b)

    {

        if(a > b)

            a = a - b;

        else b = b - a;

    }

    if(a != 1)

    {

        out << a;

    }

    else out << 0;

    out.close();

    in.close();

    return 0;

}
