#include <bits/stdc++.h>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

char *p,e[100010];

int suma(),termen(),factor(),numar();

int main()

{

    f>>e;

    p=e;

    g<<suma();

    return 0;

}

int suma()

{

    int rez=termen();

    while(*p=='+'||*p=='-')

    {

        if(*p=='+'){p++;rez+=termen();}

        else{p++;rez-=termen();}

    }

    return rez;

}

int termen()

{

    int rez=factor();

    while(*p=='*'||*p=='/')

    {

        if(*p=='*'){p++;rez*=factor();}

        else{p++;rez/=factor();}

    }

    return rez;

}

int factor()

{

    if(*p!='(')

        return numar();

    p++;

    int rez=suma();

    p++;

    return rez;

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
