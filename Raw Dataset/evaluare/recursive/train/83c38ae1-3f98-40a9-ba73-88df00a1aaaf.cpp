#include <bits/stdc++.h>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

const int N = 100010;

char E[N],*p;

int suma(),produs(),factor(),paranteza(),numar();

int main()

{

    f>>E;

    p=E;

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

    if(*p=='(')

    {

        p++;

        int rez=suma();

        p++;

        return rez;

    }

    return numar();

}

int numar()

{

    int rez=0;

    while(isdigit(*p))

    {

        rez=10*rez+*p-'0';

        p++;

    }

    return rez;

}
