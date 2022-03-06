#include <iostream>
#include <fstream>


std::ifstream in("evaluare.in");

std::ofstream out("evaluare.out");



const int N=100000;

static char s[N+1];

int p=0;



int expresie();

int termen();

int factor();



int expresie()

{

    int sum=termen();

    while(s[p]=='+' || s[p]=='-')

    {

        if(s[p]=='+')

        {

            p++;

            sum+=termen();

        }

        else if(s[p]=='-')

        {

            p++;

            sum-=termen();

        }

    }



    return sum;

}



int termen()

{

    int prod=factor();

    while(s[p]=='*' || s[p]=='/')

    {

        if(s[p]=='*')

        {

            p++;

            prod*=factor();

        }

        else if(s[p]=='/')

        {

            p++;

            prod/=factor();

        }

    }



    return prod;



}



int factor()

{

    int semn=1;

    int val=0;



    if(s[p]=='-')

    {

        semn*=-1;

        p++;

    }



    if(s[p]=='(')

    {

        p++;

        val=expresie();

        p++;

        return semn*val;

    }



    while(isdigit(s[p]))

    {

        val=val*10+(s[p++]-'0');

    }

    return semn*val;

}



int main()

{

    in.getline(s, N+1);

    out<<expresie();

    return 0;

}
