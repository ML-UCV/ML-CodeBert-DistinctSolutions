#include <bits/stdc++.h>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



char s[100005], *p;



int termen();

int factor();

int ecuatie();



int termen()

{

    int rez = factor();

    while(*p == '*' || *p == '/')

    {

        if(*p == '*')

            p++, rez *= factor();

        else

            p++, rez /= factor();

    }



    return rez;

}



int factor()

{

    int rez=0;



    if(*p == '(')

        p++, rez = ecuatie(),p++;

    else

    {

        while(isdigit(*p))

        {

            rez = rez * 10 + *p - '0';

            p++;

        }

    }



    return rez;

}



int ecuatie()

{

   int rez = termen();

   while(*p == '+' || *p == '-')

   {

       if(*p=='+')

        p++, rez += termen();

       else

        p++, rez -= termen();



   }

   return rez;

}

int main()

{

    f >> s;

    p = s;

    g << ecuatie();

}
