#include <bits/stdc++.h>


using namespace std;



const int Nmax = 1e5 + 5;

char *p,S[Nmax];

int eval();

int termen();

int factor();



int factor()

{

    int r = 0;

    if(*p == '(')

    {

        ++p;

        r = eval();

        ++p;

    }

    else while(isdigit(*p))

        {

            r = r*10 + *p - '0';

            ++p;

        }

    return r;

}

int termen()

{

    int r = factor();

    while(*p == '*' || *p == '/')

    {

        if(*p == '*')

        {

            ++p;

            r *= factor();

        }

        else

        {

            ++p;

            r /= factor();

        }

    }

    return r;

}

int eval()

{

    int r = termen();

    while(*p == '+' || *p == '-')

    {

        if(*p == '+')

        {

            ++p;

            r += termen();

        }

        else

        {

            ++p;

            r -= termen();

        }

    }

    return r;

}



int main()

{

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);



    cin.getline(S,sizeof(S));

    p = S;

    cout << eval();

    return 0;

}
