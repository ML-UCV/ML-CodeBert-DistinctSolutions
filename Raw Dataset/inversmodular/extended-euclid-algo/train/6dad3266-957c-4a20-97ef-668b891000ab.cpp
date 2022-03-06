#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

void euclid (int a, int b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
    }
    else
    {
        long long x1, y1;
        euclid(b, a%b, x1, y1);
        x = y1;
        y = x1 - y1 * (a/b);
    }
}

int main()
{


    int a, n;
    fin >> a >> n;
    long long r, g;
    euclid(a, n, r, g);
    if (r < 0)
        r = (r+n)%n;
    fout << r%n;
    return 0;
}
