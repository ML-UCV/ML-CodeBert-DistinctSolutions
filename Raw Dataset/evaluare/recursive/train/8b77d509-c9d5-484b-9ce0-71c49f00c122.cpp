#include <bits/stdc++.h>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

char *p,s[100005];

int nr()

{

    int rez=0;

    while(isdigit(*p))

    {

        rez=rez*10+*p-'0';

        p++;

    }

    return rez;

}

int eval();

int termen();

int factor();

int main()

{

    f.getline(s,100000);

    p=s;

    g<<eval()<<'\n';

    return 0;

}

int eval()

{

    int r=termen();

    while(*p=='+' || *p=='-')

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

int termen()

{

    int r=factor();

    while(*p=='*' || *p=='/')

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

        r=nr();

    return r;

}
