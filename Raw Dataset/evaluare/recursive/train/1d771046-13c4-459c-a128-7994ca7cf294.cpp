#include <bits/stdc++.h>


using namespace std;



ifstream f ("evaluare.in");

ofstream g ("evaluare.out");



char a[100005];

char *p = a;



int Eval();

int Termen();

int Factor();



int Eval()

{

    int r = Termen();



    while(*p == '+' || *p == '-')

    {

        if(*p == '+')

        {

            ++p;

            r += Termen();

        }

        else

        {

            ++p;

            r -= Termen();

        }

    }



    return r;

}



int Termen()

{

    int r = Factor();



    while(*p == '*' || *p == '/')

    {

        if(*p == '*')

        {

            ++p;

            r *= Factor();

        }

        else

        {

            ++p;

            r /= Factor();

        }

    }



    return r;

}



int Factor()

{

    int r = 0;



    if(*p == '(')

    {

        ++p;

        r = Eval();

        ++p;

    }

    else while(isdigit(*p))

        r = r * 10 + *p - '0' , p++;



    return r;

}



int main()

{

    f >> a;

    g << Eval();

    return 0;

}
