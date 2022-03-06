#include <fstream>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



int n;



bool IsPrime (int x)

{

    if (x <= 1) return false;

    if (x != 2 && !(x & 1)) return false;

    for (int i = 3; i * i <= x; i += 2)

        if (x % i == 0)

            return false;

    return true;



}



int Phi (int x)

{

    int f, phi;

    if (IsPrime(x))

        return x - 1;

    phi = x;

    f = 2;

    while (f * f <= x && x > 1)

    {

        if (!(x % f))

        {

            while (!(x % f))

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



int Fap (int a, int b)

{

    int p = 1;

    while (b)

    {

        if (b & 1)

            p = 1LL * p * a % n;

        b >>= 1;

        a = 1LL * a * a % n;

    }

    return p;

}



void Solve ()

{

    int a;

    fin >> a >> n;

    fout << Fap(a, Phi(n) - 1);

    fout.close();

}



int main()

{

    Solve();

    return 0;

}
