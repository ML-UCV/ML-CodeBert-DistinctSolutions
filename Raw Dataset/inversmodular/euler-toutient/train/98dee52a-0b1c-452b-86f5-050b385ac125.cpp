#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");




typedef unsigned long long mare;

int phi(int n)
{
    int rez = n;
    int d;
    for (d = 2; d*d<=n; d++)
        if (n%d == 0)
        {
            rez = rez / d * (d-1);
            while (n%d == 0)
                n = n/d;
        }
    if (n > 1)
        rez = rez / n * (n-1);
    return rez;
}

int invmod(int a, int n)
{

    int e = phi(n)-1;
    mare b = a, rez = 1;
    while (e > 0)
    {
        if (e&1)
            rez = rez * b % n;
        b = b*b % n;
        e >>= 1;
    }
    return rez;
}

int main()
{
    int a, n;
    fin >> a >> n;
    fout << invmod(a, n);
    return 0;
}
