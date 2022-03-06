#include <iostream>
#include <fstream>




using namespace std;



int cmmdc(int a, int b)

{

    if (a < b)

        swap(a, b);

    while (a != b)

    {

        if (a > b)

            a = a - b;

        else

            b = b - a;



    }

    return a;

}



int main()

{

    ifstream f("cmmdc.in");

    int a, b;

    f >> a >> b;

    int cmmdcNR = cmmdc(a, b);







    ofstream g("cmmdc.out");

    if (cmmdcNR == 1)

        g << 0;

    else

        g << cmmdcNR;

}
