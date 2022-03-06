#include<bits/stdc++.h>
using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

const int N = 100010;

int p;

char s[N];

int suma(),produs(),factor(),numar();

int main()

{

    f>>s;

    g<<suma();

    return 0;

}

int suma()

{

    int ret=produs();

    while(s[p]=='+'||s[p]=='-')

    {

        if(s[p]=='+'){p++;ret+=produs();}

        else {p++;ret-=produs();}

    }

    return ret;

}

int produs()

{

    int ret=factor();

    while(s[p]=='*'||s[p]=='/')

    {

        if(s[p]=='*'){p++;ret*=factor();}

        else {p++;ret/=factor();}

    }

    return ret;

}

int factor()

{

    if(s[p]=='(')

    {

        p++;

        int ret=suma();

        p++;

        return ret;

    }

    return numar();

}

int numar()

{

    int ret=0;

    while(isdigit(s[p]))

    {

        ret=10*ret+s[p]-'0';

        p++;

    }

    return ret;

}
