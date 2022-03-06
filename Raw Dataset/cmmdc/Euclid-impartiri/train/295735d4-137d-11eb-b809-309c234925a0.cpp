#include <iostream>
#include <fstream>

int gcd(int a, int b)
{
    int m;
    while (b != 0)
    {
        m = b;
        b = a % b;
        a = m;
    }
    return a;
}

int main()
{
    std::ifstream fin("cmmdc.in");
    std::ofstream fout("cmmdc.out");
    int a, b;
    fin >> a >> b;
    a = gcd(a, b);
    if (a == 1)
        fout << 0;
    else
        fout << a;
}
