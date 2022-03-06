#include <fstream>
#include <iostream>



using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

long long n,m;


long long PHI(long long nr) {
    long long phi = nr;
    for (long long i = 2; i * i <= nr; ++i) {
        if (nr % i == 0) {
            while (nr % i == 0)
                nr /= i;
            phi = (phi / i) * (i - 1);
        }
    }
    if (nr != 1)
        phi = phi / nr * (nr - 1);
    return phi;
}

int main() {
    fin >> n >> m;
    long long exponent = PHI(m) - 1;
    long long inverse = 1;


    for (long long pow = 1; pow <= exponent; pow <<= 1) {
        if (pow & exponent)
            inverse = (inverse * n) % m;
        n = (n * n) % m;
    }
    fout << inverse;

    return 0;
}
