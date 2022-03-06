#include <fstream>


using namespace std;



int N, A;



int GetPhi(int x)

{

    int phi = x;

    for (int i = 2;i * i <= x;++i)

    {

        if (x % i == 0)

        {

            while (x % i == 0)

                x /= i;

            phi = phi / i * (i - 1);

        }

    }

    if (x != 1)

        phi = phi / x * (x - 1);

    return phi;

}



int lgput(int base, int exp)

{

    int res = 1;

    while (exp > 0)

    {

        if (exp % 2)

            res = (1LL * res * base) % N;

        base = (1LL * base * base) % N;

        exp /= 2;

    }

    return res;

}



int main()

{

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    fin >> A >> N;

    fout << lgput(A, GetPhi(N) - 1) << "\n";

    fin.close();

    fout.close();

    return 0;

}
