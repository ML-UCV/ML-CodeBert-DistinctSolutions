#include <fstream>
#include <iostream>


using namespace std;



const int N = 50005;



int a, n;



bool IsPrime (int x)

{

    if (x <= 1) return false;

    if (!(x & 1) && x != 2) return false;

    for (int i = 3; i * i <= x; i += 2)

        if (!(x % i)) return false;

    return true;

}



int Euler_Totient (int x)

{

    if (IsPrime(x)) return x - 1;

    int f, phi;

    phi = x;

    f = 2;

    while (f * f <= x && x > 1)

    {

        if (x % f == 0)

        {

            while (x % f == 0)

                x /= f;

            phi /= f;

            phi *= (f - 1);

        }

        f++;

    }

    if (x > 1)

    {

        phi /= x;

        phi *= (x - 1);

    }

    return phi;

}



int Power (int a, int b, int mod)

{

    int p = 1;

    while (b)

    {

        if (b & 1)

            p = 1LL * p * a % mod;

        b >>= 1;

        a = 1LL * a * a % mod;

    }

    return p;

}



void Read ()

{

    ifstream fin ("inversmodular.in");

    fin >> a >> n;

    fin.close();

}



void Solve ()

{

    ofstream fout ("inversmodular.out");

    fout << Power(a, Euler_Totient(n) - 1, n) << "\n";

    fout.close();

}



int main()

{

    Read();

    Solve();

    return 0;

}
