#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int a, n;

void Read()

{

    fin >> a >> n;

    fin.close();

}

void EuclidExtins(int a, int b, int &x, int &y)

{

    if(b == 0)

    {

        x = 1;

        y = 0;

    }

    else

    {

        int x0, y0;

        EuclidExtins(b, a % b, x0, y0);

        x = y0;

        y = x0 - (a / b) * y0;

    }

}

int main()

{

    Read();

    int x, y;

    EuclidExtins(a, n, x, y);

    int inversmodular = x;

    while(inversmodular < 0) inversmodular += n;

    fout << inversmodular;

    return 0;

}
