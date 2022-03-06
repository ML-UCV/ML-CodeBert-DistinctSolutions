#include <fstream>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

const int N = 100010;

char s[N],*p;

int suma(),produs(),factor();

int main()

{

    f>>s;

    p=s;

    g<<suma();

    return 0;

}

int suma()

{

    int rez=produs();

    while(*p=='+'||*p=='-')

    {

        if(*p=='+'){p++;rez+=produs();}

        else {p++;rez-=produs();}

    }

    return rez;

}

int produs()

{

    int rez=factor();

    while(*p=='*'||*p=='/')

    {

        if(*p=='*'){p++;rez*=factor();}

        else {p++;rez/=factor();}

    }

    return rez;

}

int factor()

{

    int rez;

    if(*p=='(')

    {

        p++;

        rez=suma();

        p++;

        return rez;

    }

    rez=0;

    while(isdigit(*p))

    {

        rez=10*rez+*p-'0';

        p++;

    }

    return rez;



}
