#include <fstream>


std::ifstream in("cmmdc" ".in");

std::ofstream out("cmmdc" ".out");

int main()

{

    int a, b;

    in >> a >> b;

    while (a %= b)

        std::swap(a, b);

    if (b == 1)

        b = 0;

    out << b;

}
