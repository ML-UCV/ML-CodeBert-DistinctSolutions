#include <iostream>
#include <fstream>
using namespace std;



 unsigned int a, b;

ifstream citire("cmmdc.in");

ofstream afisare("cmmdc.out");

int main()

{

    while (!citire.eof())

        citire >> a >> b;

    while (a != b)

    {

        if (a > b)

            a = a - b;

        else

            b = b - a;

    }

    if (a == 1)

    {

        a = 0;

    }



    afisare << a;

    afisare.close();

    system("pause");

    return 0;

}
