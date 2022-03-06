#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");



void euclid(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
    }
    else
    {
        int x0, y0;
        euclid(b, a%b, x0, y0);
        x = y0;
        y = x0 - (a/b) * y0;
    }
}

int main()
{
    int a, n;
    fin >> a >> n;
    int rez, gunoi;

    euclid(a, n, rez, gunoi);
    if (rez > 0)
        fout << rez;
    else
        fout << rez + n;
    return 0;
}
