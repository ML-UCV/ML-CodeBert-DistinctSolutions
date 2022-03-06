#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

long long n;

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
        x = (x+n)%n;
        y = (y+n)%n;
    }
}

int main()
{


    int a;
    fin >> a >> n;
    long long r, g;
    euclid(a, n, r, g);
    fout << r;
    return 0;
}
