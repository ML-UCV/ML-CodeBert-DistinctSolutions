#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

long long mod, a;

long long log_exp (long long base, long long power){
    long long to_return;

    if (power == 1ll) return (base%mod);

    long long aux = power % 2;
    switch (aux){
        case 0ll:
            to_return = log_exp((base%mod) * (base%mod), power/2) % mod;
            break;

        case 1ll:
            to_return = (base%mod * ((log_exp((base%mod) * (base%mod), power/2)) %mod));
            break;
    }

    return to_return;
}

int getphi(int n)
{
    int result = n;



    for (int p = 2; p * p <= n; ++p) {


        if (n % p == 0) {


            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }



    if (n > 1)
        result -= result / n;
    return result;
}


int main(void){
    fin.open("inversmodular.in");
    fin>>a>>mod;
    fin.close();

    long long result, exponent = getphi(mod);

    result = log_exp(a, (exponent-1));

    fout.open("inversmodular.out");
    fout<<(result%mod)<<"\n";
    fout.close();

    return 0;
}
