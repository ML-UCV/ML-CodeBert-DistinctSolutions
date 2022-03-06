#include <fstream>


using namespace std;



ifstream inf("inversmodular.in");

ofstream outf("inversmodular.out");



int modinv(int a, int b) {

    long long x1 = 1, x2 = 0, q, aux, auxb = b;

    while(b) {

        q = a / b;

        aux = b;

        b = a - q * b;

        a = aux;

        aux = x2;

        x2 = x1 - q * x2;

        x1 = aux;

    }

    if(x1 < 0) {

        x1 += auxb;

    }

    return x1;

}



int main() {

    int a, b;

    inf >> a >> b;

    outf << modinv(a, b);

    return 0;

}
