#include <fstream>


using namespace std;



ifstream in ("evaluare.in");

ofstream out ("evaluare.out");



const int N = 100000;

char s[N + 1];

int p;



int expresie ();

int termen ();

int factor ();



int expresie ()

{

    int sum = termen ();

    while (s[p] == '+' || s[p] == '-')

    {

        if (s[p] == '+')

        {

            p++;

            sum += termen();

        }

        if (s[p] == '-')

        {

            p++;

            sum -= termen();

        }

    }

    return sum;

}



int termen ()

{

    int prod = factor ();

    while (s[p] == '*' || s[p] == '/')

    {

        if (s[p] == '*')

        {

            p++;

            prod *= factor();

        }

        if (s[p] == '/')

        {

            p++;

            prod /= factor();

        }

    }

    return prod;

}



int factor ()

{

    int semn = 1, val = 0;

    while (s[p] == '-')

    {

        p++;

        semn = -semn;

    }

    if (s[p] == '(')

    {

        p++;

        val = expresie();

        p++;

        return semn * val;

    }

    while (s[p] >= '0' && s[p] <= '9')

    {

        val = val * 10 + (s[p] - '0');

        p++;

    }

    return semn * val;

}



int main()

{

    p = 0;

    in >> s;

    out << expresie ();

    in.close();

    out.close();

    return 0;

}
