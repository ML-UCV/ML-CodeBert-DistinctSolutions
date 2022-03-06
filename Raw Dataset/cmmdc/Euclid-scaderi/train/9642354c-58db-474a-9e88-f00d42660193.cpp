#include <iostream>
#include <fstream>


using namespace std;



ifstream intrare("cmmdc.in");

ofstream iesire("cmmdc.out");



int main()

{

    int a, b;

    intrare >> a;

    intrare >> b;

    while(a != b)

        if(a > b)

            a = a - b;

        else

            b = b -a;

    int cmmdc = a;

    if(cmmdc == 1)

        iesire << 0;

        else

        iesire << cmmdc;





    return 0;

}
