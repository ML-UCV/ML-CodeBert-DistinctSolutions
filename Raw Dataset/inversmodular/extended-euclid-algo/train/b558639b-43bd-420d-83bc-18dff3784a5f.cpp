#include <fstream>


std::ifstream fin("inversmodular.in");

std::ofstream fout("inversmodular.out");



int gcd(int a, int b, int& x, int& y) {

    if (!b) {

        x = 1;

        y = 0;

        return a;

    }



    int x0, y0;

    int d = gcd(b, a % b, x0, y0);



    x = y0;

    y = x0 - a / b * y0;

    return d;

}



int main() {

    int a, n;

    fin >> a >> n;



    int x, y;

    gcd(a, n, x, y);



    if (x < 0)

        x += n;

    fout << x << '\n';



    fout.close();

    return 0;

}
