#include <bits/stdc++.h>


using namespace std;

int i;

char a[100005], *p=a;

long long termen();

long long factor();

long long eval()

{

    long long r=termen();

    while(*p=='+' || *p=='-')

    {

        switch(*p)

        {

            case('+'):

            p++;

            r=r+termen();

            break;

            case('-'):

            p++;

            r=r-termen();

            break;

        }

    }

    return r;

}

long long termen()

{

    long long r=factor();

    while (*p=='*' || *p=='/')

    {

        switch(*p)

        {

            case'*':

            p++;

            r= r* factor();

            break;

        case'/':

            p++;

            r = r/factor();

            break;

        }

    }

    return r;

}

long long factor()

{

    long long r=0;

    if(*p=='(')

    {

        p++;

        r=eval();

        p++;

    }

    else

    {

        while(*p>='0' && *p<='9')

        {

            r = r*10+*p-'0';

            p++;

        }

    }

    return r;



}

int main()

{

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");

    fin >> a;

    fout << eval();

    return 0;

}
