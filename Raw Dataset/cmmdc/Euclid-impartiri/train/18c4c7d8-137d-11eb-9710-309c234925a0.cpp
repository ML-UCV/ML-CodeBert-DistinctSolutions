#include <iostream>
#include <fstream>


using namespace std;



ifstream in("cmmdc.in");

ofstream out("cmmdc.out");





int cmmdc(int a, int b) {

    if (a == 0 || b == 0) return a;

    if (a % b == 0) return b;

    if (a != 0 && b != 0) {

        a = a % b;

        return cmmdc(b, a);

    }

    return 0;

}



int main()

{

    int a, b, r;

    in >> a;

    in >> b;



    if (a > b)

        r = cmmdc(a, b);

    else

        r = cmmdc(b, a);



    if (r == 1) out << 0;

    else out << r;

    return 0;

}
