#include <bits/stdc++.h>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

char s[100005],*p;

int factor();

int elem();

int termen()

{

    int rez=factor();

    while(*p=='+'||*p=='-')

    {

        if(*p=='+')

        {

             p++;

             rez=rez+factor();

        }

        else

        {

            p++;

            rez=rez-factor();

        }

    }

    return rez;

}

int factor()

{

    int rez=elem();

    while(*p=='*'||*p=='/')

    {

        if(*p=='*')

        {

            p++;

            rez=rez*elem();

        }

        else

        {

            p++;

            rez=rez/elem();

        }

    }

    return rez;

}

int elem()

{ int rez=0;

    if(*p=='(')

    {

        p++;

        rez=termen();

        p++;

        return rez;

    }



    while(isdigit(*p))

    {

        rez=rez*10+*p-'0';

        p++;

    }

    return rez;

}

int main()

{

    fin>>s;

    p=s;

    fout<<termen();

    return 0;

}
