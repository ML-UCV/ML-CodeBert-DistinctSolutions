#include <iostream>
#include <fstream>


using namespace std;



ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int main()

{

    int a, b;

    f >> a >> b;

    int cmmdc = 0;

    for (int i = 2; i <= min(a, b); i++) {

        if (a % i == 0 && b % i == 0) {

            cmmdc = i;

        }

    }

    g << cmmdc;

    return 0;

}
