#include <iostream>
#include <fstream>


using namespace std;



int main()

{

    ifstream in;

    ofstream out;

    int a, b;



    in.open("cmmdc.in");

    out.open("cmmdc.out");



    in >> a >> b;

    while (a != b){

        if (a > b)

            a -= b;

        if (b > a)

            b -= a;

    }



    if (a == 1)

        out << 0;

    else

        out << a;

    return 0;

}
