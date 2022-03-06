#include <bits/stdc++.h>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

char s[100005];

int poz,n;

int eval();

int factor();

int termen();

int eval()

{

    int rez=termen();

    while (poz<n&&(s[poz]=='+'||s[poz]=='-'))

    {

        if (s[poz]=='+')

        {

            poz++;

            rez=rez+termen();

        }

        else

        {

            poz++;

            rez=rez-termen();

        }

    }

    return rez;

}

int termen()

{

    int rez=factor();

    while (poz<n&&(s[poz]=='*'||s[poz]=='/'))

    {

        if (s[poz]=='*')

        {

            poz++;

            rez=rez*factor();

        }

        else

        {

            poz++;

            rez=rez/factor();

        }

    }

    return rez;

}

int factor ()

{

    int rez=0;

    if (s[poz]=='(')

    {

            poz++;

            rez=eval();

            poz++;

    }

    while(s[poz]>='0' && s[poz]<='9')

    {

        rez=rez*10+(s[poz]-'0');

        poz++;

    }

    return rez;

}

int main()

{

    f.getline(s,100005);

    n=strlen(s);

    poz=0;

    g<<eval();

    return 0;

}
