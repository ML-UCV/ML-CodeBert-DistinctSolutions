#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



char s[100005],*p;

int eval();

int termen();

int factor();





int main()

{

    f.getline(s,100005);

    p=s;

    int rez=eval();

    g<<rez;

    return 0;

}

int factor()

{

    int r=0;

    if(*p=='(')

    {

        p++;

        r=eval();

        p++;

    }

    else

    {

        while(*p>='0'&&*p<='9')

        {

            r=r*10+(*p-'0');

            p++;

        }

    }

    return r;

}

int termen()

{

    int r=factor();

    while(*p=='*'||*p=='/')

    {

        if(*p=='*')

        {

            p++;

            r*=factor();

        }

        else

        {

            p++;

            r/=factor();

        }

    }

    return r;

}

int eval()

{

    int r=termen();

    while(*p=='+'||*p=='-')

    {

        if(*p=='+')

        {

            p++;

            r+=termen();

        }

        else

        {

            p++;

            r-=termen();

        }

    }

    return r;

}
