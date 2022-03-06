#include <fstream>


using namespace std;



ifstream f ("inversmodular.in");

ofstream g ("inversmodular.out");



long long A, N, inv, ins;



void gcd (long long a, long long b, long long &x, long long &y) {

    if (!b) {

        x = 1, y = 0;

    }



    else {

        gcd (b, a % b, x, y);

        long long aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}



int main() {

    f >> A >> N;



    gcd (A, N, inv, ins);

    if (inv < 0) {

        inv = inv % N + N;

    }



    inv %= N;

    g << inv << '\n';

}
