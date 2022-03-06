#include <iostream>
#include <fstream>


using namespace std;



int cmmdc(int a, int b)

{

    if (b == 0) return a;

    else return cmmdc(b, a%b);



}





int main(){

ifstream fisier("cmmdc.in"); ofstream ofisier("cmmdc.out");

int x, y;

    fisier >> x;

    fisier >> y;

    if (cmmdc(x, y) == 1) ofisier << 0;

    else ofisier << cmmdc(x, y);

    return 0;

}
