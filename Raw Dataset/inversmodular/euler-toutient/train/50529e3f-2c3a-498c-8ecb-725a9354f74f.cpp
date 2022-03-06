#include <iostream>
#include <fstream>




using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



long long eulerTotient(long long n) {

    long long sol = n;

    if (n % 2 == 0) {

        sol = sol / 2;

        while (n % 2 == 0)

            n /= 2;

    }

    for (int d = 3; d * d <= n; d += 2)

        if (n % d == 0) {

            sol = sol / d * (d - 1);

            while (n % d == 0)

                n /= d;

        }

    if (n > 1)

        sol = sol / n * (n - 1);

    return sol;

}



long long raise(long long base, long long exp, long long n) {

    long long result = 1;

    while (exp) {

        if (exp & 1)

            result = (result * base) % n;

        base = (base * base) % n;

        exp >>= 1;

    }

    return result;

}



int main() {

    long long a, n;

    fin >> a >> n;

    fout << raise(a, eulerTotient(n) - 1, n);

    return 0;

}
