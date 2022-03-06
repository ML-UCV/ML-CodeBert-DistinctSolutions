#include <fstream>


std::ifstream in("evaluare" ".in");

std::ofstream out("evaluare" ".out");

char S[100001]; int i, zero();

int doi()

{

    if (S[i] == '(')

        return i++, zero();

    int n = 0;

    while ('0' <= S[i] and S[i] <= '9')

        (n *= 10) += S[i++] - '0';

    return n;

}

int unu()

{

    int p = doi();

    for (;;)

        switch (S[i++])

        {

            case '*': p *= doi(); break;

            case '/': p /= doi(); break;

            default: i--; return p;

        }

}

int zero()

{

    int s = 0, semn = 1;

    while (s += semn * unu(), S[i] and S[i] != ')')

        semn = (S[i++] == '+'? 1: -1);

    i++; return s;

}

int main()

{

    in >> S;

    out << zero();

}
