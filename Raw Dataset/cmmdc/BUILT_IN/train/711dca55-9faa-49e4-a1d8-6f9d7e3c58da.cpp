#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int a, b, x;

int main()

{

    f >> a >> b;

    x = __gcd(a, b);



    if(x == 1)

        g << "0\n";

    else

        g << x << "\n";



    return 0;

}
