#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void modularInverse(int a, int n, int &inverse, int &x) {

    if (!n) {

        inverse = 1;

        x = 0;

        return;

    }

    modularInverse(n, a % n, inverse, x);

    int aux = inverse;

    inverse = x;

    x = aux - x * (a / n);

}



int main() {

    int a, n, inverse, x;

    fin >> a >> n;

    modularInverse(a, n, inverse, x);

    if (inverse < 0)

        inverse += n;

    fout << inverse;

    return 0;

}
