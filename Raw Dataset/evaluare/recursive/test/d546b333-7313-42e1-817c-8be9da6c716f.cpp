#include <bits/stdc++.h>
using namespace std;

ifstream in ("evaluare.in");

ofstream out ("evaluare.out");

string s;

int p = 0;

int eval(), factor(), nr(), termen();

int nr ()

{

    int rez = 0;

    while (isdigit(s[p]))

        rez = rez * 10 + s[p++]-'0';

    return rez;

}



int factor ()

{

    if (s[p]=='(')

    {

        p++;

        int k = eval();

        p++;

        return k;

    }

    else

        return nr();

}



int termen ()

{

    int r = factor ();

    while (s[p]=='*' || s[p]=='/')

    {

        if (s[p]=='*')

            p++,r *= factor();

        else

            p++,r /= factor();

    }

    return r;

}



int eval ()

{

    int r = termen();

    while (s[p]=='+' || s[p]=='-')

    {

        if (s[p]=='+')

            p++, r += termen();

        else

            p++, r -= termen();

    }

    return r;

}

int main ()

{

    in>>s;

    out<<eval();

    return 0;

}
