#include <iostream>
#include <fstream>
using namespace std;



char Exp[100001],*p;



int Evaluare();



int Nr()

{

    int Val=0;

    if(*p=='(')

    {

        p++;

        Val=Evaluare();

        p++;

    }

    else

        while(*p>='0' && *p<='9')

        {

            Val=Val*10 + (*p-'0');

            p++;

        }

    return Val;

}

int Or2()

{

    int Val=Nr();

    while(*p=='/' || *p=='*')

        if(*p=='/')

        {

            p++;

            Val/=Nr();

        }

        else

        {

            p++;

            Val*=Nr();

        }

    return Val;

}

int Evaluare()

{

    int Val=Or2();

    while(*p=='+' || *p=='-')

        if(*p=='+')

        {

            p++;

            Val+=Or2();

        }

        else

        {

            p++;

            Val-=Or2();

        }

    return Val;

}

int main()

{

    ifstream f("evaluare.in");

    f.get(Exp,100001);

    f.close();

    ofstream g("evaluare.out");

    p = Exp;

    g<<Evaluare();

    return 0;

}
