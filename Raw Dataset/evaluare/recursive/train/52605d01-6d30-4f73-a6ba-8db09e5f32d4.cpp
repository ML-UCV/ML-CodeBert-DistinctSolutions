#include <iostream>
#include <fstream>
using namespace std;



const long n = 100001;

char calc[n], *pa = calc;



long sd();



long paranteze()

{

    long r = 0;

    if (*pa == '(')

    {

        pa++;

        r = sd();

        pa++;

    }

    else

    {

        while (*pa >= '0' && *pa <= '9')

        {

            r = r * 10 + *pa - '0';

            pa++;

        }

    }

    return r;

}



long inip()

{

    long r = paranteze();

    while (*pa == '*' || *pa == '/')

    {

        if (*pa == '*')

        {

            pa++;

            r *= paranteze();

        }

        else

        {

            pa++;

            r /= paranteze();

        }

    }

    return r;

}



long sd()

{

    long r = inip();

    while (*pa == '+' || *pa == '-')

    {

        if (*pa == '+')

        {

            pa++;

            r += inip();

        }

        else

        {

            pa++;

            r -= inip();

        }

    }

    return r;

}



int main()

{

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");

    fin.getline(calc, n);

    fout << sd();

    return 0;

}
