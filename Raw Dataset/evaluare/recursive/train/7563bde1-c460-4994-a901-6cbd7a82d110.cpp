#include <iostream>
#include <fstream>
using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

char s[100001],*p;

int r;

int eval();

int termene();

int factor();

int eval()

{

    int r=termene();

    while(*p=='+'||*p=='-')

    {

        if(*p=='+') p++,r+=termene();

        else p++,r-=termene();

    }

    return r;

}

int termene()

{

    int r=factor();

    while(*p=='*'||*p=='/')

    {

        if(*p=='*') p++,r*=factor();

        else p++,r/=factor();

    }

    return r;

}

int factor()

{

    int r=0;

    if(*p=='(')

        p++,r=eval(),p++;

    else while('0'<=*p&&'9'>=*p)

            r=r*10+*p-'0',p++;

    return r;

}int main()

{

    f.getline(s,100001);

    p=s;

    r=eval();

    g<<r;

    return 0;

}
