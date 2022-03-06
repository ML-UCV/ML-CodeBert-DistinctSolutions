#include <bits/stdc++.h>
using namespace std;

ifstream f ("evaluare.in");

ofstream g ("evaluare.out");

char s[100002];



char *t=s;

int getnr()

{



    int nr=0;

    while(*t>='0' && *t<='9')

    {

        nr*=10;

        nr+=*t-'0';

        ++t;

    }



    return nr;

}

int prod();

int parant();

int sum()

{

    int r=prod();



    while(*t=='+' || *t=='-')

    {

        if(*t=='+')

        {

             ++t;

             r+=prod();

        }



        else

        {

             ++t;

             r-=prod();

        }



    }



    return r;

}

int prod()

{

    int r=parant();



    while(*t=='*' || *t=='/')

    {

        if(*t=='*')

        {



           ++t;

           r*=parant();

        }



        else {

            ++t;

            r/=parant();

        }



    }



    return r;

}

int parant()

{

    int r=0;



    if(*t=='(')

    {

       ++t;

       r= sum();

            ++t;

    }



    else r= getnr();





    return r;

}



int main()

{

    f>>s;

    g<<sum();

    return 0;

}
