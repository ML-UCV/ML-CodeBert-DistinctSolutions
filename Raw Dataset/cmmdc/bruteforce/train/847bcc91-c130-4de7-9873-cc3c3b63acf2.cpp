#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;



ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int main()

{

    int a, b, x = 1;

    f >> a >> b;

    for (int i = 1; i <= a; i++)

    {

        if (a % i == 0 && b % i == 0) x = i;

    }

    if (x == 1) g << 0;

    else g << x;



    return 0;

}
