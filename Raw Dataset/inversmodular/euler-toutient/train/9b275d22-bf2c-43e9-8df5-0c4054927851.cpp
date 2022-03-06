#include <fstream>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int Phi(int n)

{

    int sol = n , p;

    for (p = 2 ; n > 1 && p * p <= n ; p++)

        if (n % p == 0)

        {

            sol = sol / p * (p - 1);

            while (n % p == 0)

                    n /= p;

        }

    if (n > 1) sol = sol / n * (n - 1);

    return sol;

}



int lg(int a , int b , int mod)

{

    int p = 1;

    while (b > 0)

    {

        if (b % 2 == 1)

            p = 1LL * p * a % mod;

        b /= 2;

        a = 1LL * a * a % mod;

    }

    return p;

}



int main()

{

    int a , n , rez;

    fin >> a >> n;

    rez = lg(a , Phi(n) - 1 , n);

    fout << rez;

    return 0;

}
