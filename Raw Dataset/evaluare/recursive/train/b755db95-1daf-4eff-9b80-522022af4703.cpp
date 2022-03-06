#include <bits/stdc++.h>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

const int N = 100010;

char s[N],*p;

int suma(),termen(),factor(),numar();



int main()

{

    f>>s;

    p=s;

    g<<suma();

    return 0;

}

int suma()

{

    int ret=termen();

    while(*p=='+'||*p=='-')

    {

        if(*p=='+'){p++;ret+=termen();}

        else {p++;ret-=termen();}

    }

    return ret;

}

int termen()

{

    int ret=factor();

    while(*p=='*'||*p=='/')

    {

        if(*p=='*'){p++;ret*=factor();}

        else {p++;ret/=factor();}

    }

    return ret;

}

int factor()

{

    if(*p=='(')

    {

        p++;

        int ret=suma();

        p++;

        return ret;

    }

    else

        return numar();

}

int numar()

{

    int ret=0;

    while(*p>='0'&&*p<='9')

    {

        ret=10*ret+*p-'0';

        p++;

    }

    return ret;

}
