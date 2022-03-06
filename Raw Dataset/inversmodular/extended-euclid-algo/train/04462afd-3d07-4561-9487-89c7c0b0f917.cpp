#include <iostream>
#include <fstream>




using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void gcdExtended(long long a, long long b, long long &x, long long &y) {

    if (!b) {

        x = 1;

        y = 0;

        return;

    }

    gcdExtended(b, a % b, x, y);

    long long aux = x;

    x = y;

    y = aux - (a / b) * y;

}



int main() {

    long long a, n, x, y;

    fin >> a >> n;

    gcdExtended(a, n, x, y);

    if (x < 0)

        x += n;

    fout << x;

    return 0;

}
