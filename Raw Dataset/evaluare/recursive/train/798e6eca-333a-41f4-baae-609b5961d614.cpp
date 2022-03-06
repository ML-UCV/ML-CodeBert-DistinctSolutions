#include <fstream>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

char s[100000+10],*p;

int eval();

int termen();

int factor();

int eval()

{

    long long r;

    r=termen();

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

    long long r;

    r=factor();

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

    long long r;

    r=0;

    if(*p=='(' || *p=='[')

    {

        p++;

        r=eval();

        p++;

    }

    else

    while(*p>='0' && *p<='9')

    {

        r=r*10+(*p-'0');

        p++;

    }

    return r;

}

int main()

{

    f.getline(s,100010);

    p=s;

    g<<eval();



    return 0;

}
