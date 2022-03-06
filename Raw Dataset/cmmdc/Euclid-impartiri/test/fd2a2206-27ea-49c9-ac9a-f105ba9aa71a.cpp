#include <iostream>
#include <fstream>


using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int main()

{

    int a, b, c;

    f >> a >> b;

    while(b)

    {

        c = a % b;

        a = b;

        b = c;

    }

    if(a == 1)g << 0;

    else g << a;

}
