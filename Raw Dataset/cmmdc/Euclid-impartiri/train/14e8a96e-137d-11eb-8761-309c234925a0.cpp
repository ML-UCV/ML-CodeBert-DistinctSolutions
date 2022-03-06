#include <fstream>


std::ifstream in("cmmdc" ".in");

std::ofstream out("cmmdc" ".out");

int rasp()

{

    int a, b;

    in >> a >> b;

    if (!b)

        return a;

    while (a %= b)

        std::swap(a, b);

    return b == 1? 0: b;

}

int main()

{out << rasp();}
