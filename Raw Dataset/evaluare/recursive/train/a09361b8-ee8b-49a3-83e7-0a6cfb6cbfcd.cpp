#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

int l;

char op[4][4] = { "+-", "*/", "^", "" };

char c[100010],*p=c;

int eval (int a,int b,char o)

{

    switch ( o )

    {

        case '+': return a+b;

        case '-': return a-b;

        case '*': return a*b;

        case '/': return a/b;

    }

}

int expr (int niv)

{

    int x,y;

    if (niv==2)

    {

        if (*p=='(')

        {

            ++p;

            x=expr(0);

            ++p;

        }

        else

        {

            for (x=0; *p>='0' && *p<='9'; ++p)

            {

                x=x*10+*p-'0';

            }

        }

    }

    else

    {

        for (x=expr(niv+1); strchr(op[niv],*p); x=y)

        {

            y=eval(x,expr(niv+1),*p++);

        }

    }

    return x;

}

int main()

{

    f.getline(c,100001);

    l=strlen(c);

    c[l]='_';

    g<<expr(0);

    return 0;

}
