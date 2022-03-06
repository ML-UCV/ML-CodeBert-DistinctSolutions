#include <iostream>
#include <fstream>


using namespace std;



ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");





char s[100002];

int i=0;



int calc();

int termen();

int factor();



int main()

{

    fin>>s;



    fout<<calc();

}



int calc()

{

    int x=termen();



    while(s[i]=='+' || s[i]=='-')

    {

        if(s[i]=='+')

        {

            i++;

            x=x+termen();

        }



        else

        {

            i++;

            x=x-termen();

        }

    }



    i++;

    return x;

}



int termen()

{

    int x=factor();



    while(s[i]=='*' || s[i]=='/')

    {

        if(s[i]=='*')

        {

            i++;

            x=x*factor();

        }



        else

        {

            i++;

            x=x/factor();

        }

    }



    return x;

}



int factor()

{

    if(s[i]=='(')

    {

        i++;

        return calc();

    }



    else

    {

        int x=0;



        while(s[i]>='0' && s[i]<='9')

        {

            x=x*10+s[i]-'0';

            i++;

        }



        return x;

    }

}
