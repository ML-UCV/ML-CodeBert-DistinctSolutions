#include <bits/stdc++.h>
using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



string s;

char c;

int poz;



int Sum();



int termen();



int Prod();



int termen()

{

    int sum = 0;

    if(c == '(')

    {

        poz ++;

        c = s[poz];

        sum = Sum();

        poz ++;

        c = s[poz];

    }

    else

        while(c <= '9' && c >= '0')

    {

        sum = sum * 10 + c - '0';

        poz ++;

        c = s[poz];

    }

    return sum;

}



int Prod()

{

    int rez = termen();

    while(c == '*' || c == '/')

    {

        if(c == '*')

        {

            poz++;

            c=s[poz];

            rez*=termen();

        }

        else

        {

            poz++;

            c=s[poz];

            rez/=termen();

        }

    }

    return rez;



}



int Sum()

{

    int rez = Prod();

    while(c == '+' || c == '-')

    {

        if(c == '+')

        {

            poz++;

            c=s[poz];

            rez += Prod();

        }

        else

        {

            poz++;

            c=s[poz];

            rez -= Prod();

        }

    }

    return rez;

}



int main()

{

    fin >> s;

    c = s[0];



    fout << Sum();



    return 0;

}
