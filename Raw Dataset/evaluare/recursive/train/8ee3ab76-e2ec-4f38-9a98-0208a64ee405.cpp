#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char s[100005], *p = s;



long termen();

long factor();



long eval()

{

    long r = termen();

    while (*p == '+' || *p == '-')

    {

        if (*p == '+')

        {

            p++;

            r += termen();

        }

        else

        {

            p++;

            r -= termen();

        }

    }

    return r;

}



 long termen()

 {

     long r = factor();

     while (*p == '*' || *p == '/')

     {

         if (*p == '*')

         {

             p++;

             r *= factor();

         }

         else

         {

             p++;

             r /= factor();

         }

     }

     return r;

 }



long factor()

{

    long r = 0;

    if (*p == '(')

    {

        p++;

        r = eval();

        p++;

    }

    else

    {

        while (isdigit(*p))

        {

            r = r * 10 + (*p - '0');

            p++;

        }

    }

    return r;

}



int main()

{

    fin >> s;

    fout << eval() << '\n';

    return 0;

}
