#include <bits/stdc++.h>
using namespace std;

char s[100050],*p;

int eval();

int termen();

int factor();

int eval( )

{

    int r=termen();

    while(*p=='+'||*p=='-')

        if(*p=='+')

        {

            p++;

            r+=termen();

        }

        else {

            p++;

            r-=termen();

        }

    return r;

}

int termen()

{

    int r=factor();

    while(*p=='*'||*p=='/')

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

        while(*p>='0'&&*p<='9')

        {

            r=r*10+*p-'0';

            p++;

        }

    return r;

}

int main()

{

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);

    cin.sync_with_stdio(0);

    cin.tie(0);

    cin.getline(s,100000);

    p=s;

    cout<<eval();

}
