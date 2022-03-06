#include <fstream>
#include <algorithm>


using namespace std;



const int NMAX = 100005;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");



string s;

int p;



int expresie();

int termen();

int factor();



int expresie()

{

    int sum = termen();

    while(s[p] == '+' || s[p] == '-')

    {

        if(s[p] == '+')

        {

            p++;

            sum += termen();

        }

        else

        if(s[p] == '-')

        {

            p++;

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

        if(s[p] == '/')

        {

            p++;

            prod /= factor();

        }

    }

    return prod;

}



int factor()

{

    int val = 0, semn = 1;

    while(s[p] == '-')

    {

        p++;

        semn = - semn;

    }

    if(s[p] == '(')

       {

           p++;

           val = expresie();

           p++;

           return semn * val;

       }

    while(s[p] >= '0' && s[p] <= '9')

    {

        val = val * 10 + (s[p] - '0');

        p++;

    }

    return semn * val;

}



int main()

{

    cin >> s;

    cout << expresie();

    return 0;

}
