#include <fstream>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int A, N;



void gcd(long long &x, long long &y, int a, int b)

{

    if (!b)

        x = 1, y = 0;

    else

    {

        gcd(x, y, b, a % b);

        long long aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}



int main()

{

    ios::sync_with_stdio(false);

    long long inv = 0, ins;

    fin>>A>>N;

    fin.close();

    gcd(inv, ins, A, N);

    if (inv <= 0)

        inv = N + inv % N;

    fout<<inv;

    fout.close();

    return 0;

}
