#include <iostream>
#include <fstream>
using namespace std;

ifstream in("evaluare.in");

ofstream out("evaluare.out");

char s[100010];

int i = 1;



int eval();

int factor();



int numar()

{

    int r = 0;

    if(s[i] == '(')

    {

        i++;

        r = eval();

        i++;

    }

    else

    {

        while(isdigit(s[i]))

        {

            r = r * 10 + s[i] - '0';

            i++;

        }

    }

    return r;

}



int factor()

{

    int r = numar();

    while(s[i] == '*' || s[i] == '/')

    {

        if(s[i] == '*')

        {

            i++;

            r = r * numar();

        }

        else

        {

            i++;

            r = r / numar();

        }

    }

    return r;

}



int eval()

{

    int r = factor();

    while(s[i] == '-' || s[i] == '+')

    {

        int semn = 1;

        if(s[i] == '-')

            semn = -1;

        i++;

        r = r + semn * factor();

    }

    return r;

}



int main()

{

    in.getline(s + 1, 100005);

    out << eval();

    return 0;

}
