#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long n, p;

void gcd(long long &x, long long &y, int a, int b)

{

    if (!b)

        x = 1, y = 0;

    else

    {

        gcd(x,y,b,a%b);

        long long aux = x;

        x = y;

        y = aux - y*(a/b);

    }

}

int main()

{

    long long v1, v2;

    fin>>n>>p;

    gcd(v1, v2, n, p);

    while (v1<0)v1+=p;

    fout<<v1<<'\n';

    return 0;

}
