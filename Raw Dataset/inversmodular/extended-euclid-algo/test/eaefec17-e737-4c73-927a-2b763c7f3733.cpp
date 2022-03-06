#include <iostream>
#include <fstream>


std::ifstream f ("inversmodular.in");

std::ofstream g ("inversmodular.out");



using namespace std;



void extins(int a, int b, int& x, int& y) {





    int r;

    int z, t;







    if (b != 0) {



        extins(b, a%b, x, y);

    }

    if (b == 0) {

        x = 1;

        y = 0;

    }

    else {

        z = y;

        t = x - (a/b)*y;



        x = z;

        y = t;

    }

}





int main()

{



    int a, b;



    int x, y;

    f >> a >> b;



    extins(a, b, x, y);
    if (x < 0) {

        g << x + b << "\n";

    } else {

        g << x << "\n";

    }

    return 0;

}
