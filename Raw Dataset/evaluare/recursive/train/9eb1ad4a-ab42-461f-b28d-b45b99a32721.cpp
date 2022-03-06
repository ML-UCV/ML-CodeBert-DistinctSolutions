#include <fstream>
using namespace std;

ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");

char s[100001],*p=s;

int adunare ();

int inmultire ();

int paranr ();

int adunare ()

{

    int r;

    r=inmultire();

    while (*p=='+' || *p=='-')

        if (*p=='+')

        {

            p++;

            r+=inmultire();

        }

        else

            if (*p=='-')

            {

                p++;

                r-=inmultire();

            }

    return r;

}

int inmultire ()

{

    int r;

    r=paranr();

    while (*p=='*' || *p=='/')

        if (*p=='*')

        {

            p++;

            r*=paranr();

        }

        else

            if (*p=='/')

            {

                p++;

                r/=paranr();

            }

    return r;

}

int paranr ()

{

    int r=0;

    if (*p=='(')

    {

        p++;

        r=adunare();

        p++;

    }

    else

        while (*p>='0' && *p<='9')

        {

            r=r*10+*p-'0';

            p++;

        }

    return r;

}

int main ()

{

    fin.get(s,100001);

    fout<<adunare();

    return 0;

}
