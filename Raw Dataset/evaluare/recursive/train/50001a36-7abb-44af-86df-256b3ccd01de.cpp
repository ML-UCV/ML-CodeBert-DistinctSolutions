#include <bits/stdc++.h>


using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

char s[100001],*p=s;



long termen();



long factor();



long eval()

{

    long r=termen();

    while( *p == '+' || *p == '-')

        switch( *p )

    {

        case '+':

        ++p;

        r += termen();

        break;

        case '-':

        ++p;

        r -=termen();

        break;

    }

    return r;

}

long termen()

{

    long r=factor();

    while( *p == '*' || *p == '/')

        switch( *p )

            {

                case '*' :

                    ++p;

                    r*=factor();

                    break;



                case '/' :

                    ++p;

                    r/=factor();

                    break;



            }

    return r;

}

long factor()

{

    long r = 0;

    if(*p == '(' )

    {

        ++p;

        r=eval();

        ++p;

    }

    else while(*p >='0' && *p <= '9')

    {

        r=r*10 + *p - '0';

        ++p;

    }

    return r;

}

int main()

{

    fin.get(s,100001);

    fout << eval();

    return 0;

}
