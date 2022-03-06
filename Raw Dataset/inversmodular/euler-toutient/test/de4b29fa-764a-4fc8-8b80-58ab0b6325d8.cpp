#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int Phi(int n)

{

    int sol, p;

    sol = n;

    for(p = 2;n > 1 && p * p <= n;p++)

    {

        if(n % p == 0)

        {

            sol = sol / p * (p - 1);

            while(n % p == 0)

                n /= p;

        }

    }

    if(n > 1)

        sol = sol / n * (n - 1);

    return sol;

}

int invmod(int a, int n, int MOD)

{

    int sol = 1;

    while(n > 0)

    {

        if(n % 2 == 1)

            sol = 1LL * sol * a % MOD;

        n /= 2;

        a = 1LL * a * a % MOD;

    }

    return sol;

}

int a, n;



int main()

{

    fin >> a >> n;

    fout << invmod(a, Phi(n) - 1, n);

    return 0;

}
