#include <iostream>
#include <fstream>


using namespace std;



ifstream f("cmmdc.in");

ofstream fo("cmmdc.out");



int cmmdc(int a, int b) {

    if(!b)

        return a;

    return cmmdc(b, a%b);

}



int main() {

    int a, b;

    f>>a>>b;



    if(cmmdc(a, b) == 1)

        fo << 0;

    else

        fo << cmmdc(a, b);

}
