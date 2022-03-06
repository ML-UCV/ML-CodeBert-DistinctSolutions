#include <fstream>


using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



const int N = 100000;



char s[N + 1];

int expresie();

int factor();

int termen();

int p;



int expresie()

{

    int sum = termen();

    while(s[p] == '+' || s[p] == '-')

    {

        if(s[p] == '+')

        {

            p ++;

            sum += termen();

        }

        else

        {

            p ++;

            sum -= termen();

        }

    }

    return sum;

}



int termen()

{

    int prod = factor();

    while(s[p] == '*' || s[p] == '/')

    {

        if(s[p] == '*')

        {

            p++;

            prod *= factor();

        }

        else

        {

            p ++;

            prod /= factor();

        }

    }

    return prod;

}



int factor()

{

    int sign = 1,val = 0;

    while(s[p] == '-')

    {

        p ++;

        sign = -sign;

    }

    if(s[p] == '(')

    {

        p ++;

        val = expresie();

        p ++;

        return sign * val;

    }

    while(s[p] >= '0' && s[p] <= '9')

    {

        val = val * 10 + (s[p] - '0');

        p ++;

    }

    return sign * val;

}



int main()

{

    in >> s;

    out << expresie();

    return 0;

}
