#include <iostream>
#include <fstream>


using namespace std;



ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");





int termen ();

int factor();

int calc();



int i;

char s[100002];



int main()

{

    fin>>s;



    fout<<calc();

}



int calc ()

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

            x= x*factor();

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

    int x=0;



    if(s[i]=='(')

    {

        i++;

        return calc();

    }



    else

    {

        while(s[i]>='0' && s[i]<='9')

        {

            x=x*10+s[i]-'0';

            i++;

        }

        return x;

    }

}
