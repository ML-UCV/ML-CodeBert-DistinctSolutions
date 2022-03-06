#include <bits/stdc++.h>


using namespace std;

ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");

char sir[100006],*pointersir=sir;

long long termen ();

long long factor ();

long long eval ()

{

    long long r=termen();

    while(*pointersir=='+' || *pointersir=='-')

    {

        if(*pointersir=='+')

        {

            pointersir++;

            r=r+termen();

        }

        else

        {

            pointersir++;

            r=r-termen();

        }

    }

    return r;

}

long long termen ()

{

    long long r=factor();

    while(*pointersir=='*' || *pointersir=='/')

    {

        if(*pointersir=='*')

        {

            pointersir++;

            r=r*factor();

        }

        else

        {

            pointersir++;

            r=r/factor();

        }

    }

    return r;

}

long long factor ()

{

    long long r=0;

    if(*pointersir=='(')

    {

        pointersir++;

        r=eval();

        pointersir++;

    }

    else

        while(*pointersir<='9' && *pointersir>='0')

            r=r*10+*pointersir-'0',pointersir++;

    return r;

}

int main ()

{

    fin.getline(sir,100001);

    fout<<eval();

    return 0;

}
