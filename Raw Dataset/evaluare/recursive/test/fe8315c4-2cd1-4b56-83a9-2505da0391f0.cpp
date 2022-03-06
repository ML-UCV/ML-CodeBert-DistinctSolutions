#include <bits/stdc++.h>
using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");

char s[100001],*p=s;

long x;

long numar();

long fact();



long adsc()

{

    long x=numar();

    while(*p=='+' or *p=='-')

    {

        switch (*p)

        {

        case '+':

            p++;

            x=x+numar();

            break;

        case '-':

            p++;

            x=x-numar();

            break;

        }

    }

    return x;

}





long numar()

{

    long x=fact();

    while(*p=='*' or *p=='/')

    {

        {

            switch (*p)

            {

            case '*':

                p++;

                x=x*fact();

                break;

            case '/':

                p++;

                x=x/fact();

                break;

            }

        }







    }

    return x;

}





long fact()

{

    x=0;

    if(*p=='(')

    {

        p++;

        x=adsc();

        p++;

    }

    else

    {

        while(*p<='9' and *p>='0')

        {

            x=x*10+(*p-'0');

            p++;

        }



    }

    return x;

}



int main()

{

    f.get(s,100001);

    g<<adsc();



}
