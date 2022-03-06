#include <iostream>
#include <fstream>


using namespace std;

long long phi(long long x) {

    long long answer = x;

    for (int i = 2; i * i <= x; ++i) {

        if (x % i == 0) {

            answer = answer / i * (i - 1);

            while (x % i == 0) {

                   x = x / i;

            }

        }

    }

    if (x > 1) {

        answer = answer / x * (x - 1);

    }

    return answer;

}



long long power(long long a, long long b, long long mod) {

    if (b == 0) {

        return 1;

    }

    if (b % 2 == 0) {

        return power((1LL * a * a) % mod, b / 2, mod);

    } else {

        return ((1LL * a * power(a, b - 1, mod)) % mod) ;

    }

}



int main()

{

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    long long n, mod;

    fin >> n >> mod;

    fout << power(n, phi(mod) - 1, mod);



    return 0;

}
