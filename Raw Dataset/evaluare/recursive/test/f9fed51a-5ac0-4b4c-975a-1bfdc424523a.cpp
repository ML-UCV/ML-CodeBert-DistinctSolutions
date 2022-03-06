#include <iostream>
#include <fstream>

using namespace std;
ifstream f("evaluare.in");

ofstream g("evaluare.out");

char s[100000],*p;

int eval();

int termen();

int factor();

int eval()
{
    int r=termen();

    while(*p=='+' || *p=='-')
        if(*p=='+')
        {
            p++;

            r+=termen();

        }
        else if(*p=='-')
        {
            p++;

            r-=termen();

        }

    return r;


}

int termen()
{
    int r=factor();

    while(*p=='*' || *p=='/')
        if(*p=='*')
        {
            p++;

            r*=factor();

        }
        else if(*p=='/')
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
        while('0'<=*p && *p<='9')
        {
            r=r*10+*p-'0';

            p++;

        }

        return r;

}
int main()
{
    f.getline(s,100000);

    p=s;

    int rez=eval();

    g<<rez;


    return 0;
}
