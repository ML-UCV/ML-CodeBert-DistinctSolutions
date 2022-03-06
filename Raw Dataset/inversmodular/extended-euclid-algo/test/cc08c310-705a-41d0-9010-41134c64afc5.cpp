#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int a, n;

void euclidextins(int a, int b, int &x, int &y)

{

    if(b == 0)

    {

        x = 1, y = 1;

    }

    else

    {

        int x0, y0;

        euclidextins(b, a % b, x0, y0);

        x = y0;

        y = x0 - (a / b) * y0;

    }

}

int main()

{

    fin >> a >> n;

    int x, y;

    euclidextins(a, n, x, y);

    while(x < 0) x += n;

    fout << x;

    return 0;

}
