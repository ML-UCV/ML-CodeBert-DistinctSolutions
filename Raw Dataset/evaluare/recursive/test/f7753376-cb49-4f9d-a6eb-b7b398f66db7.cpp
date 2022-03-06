#include <iostream>
#include <fstream>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");



string s;

int i;

long termen();

long factor();

long eval()

{

    int x=termen();

    while(s[i]=='+'||s[i]=='-')

    {

        if(s[i]=='+')

        {

            i++;

            x+=termen();

        }

        else if(s[i]=='-')

        {

            i++;

            x-=termen();



        }

    }

    return x;

}

long termen()

{

    long x=factor();

    while(s[i]=='*'||s[i]=='/')

    {

        if(s[i]=='*')

        {

            i++;

            x=x*factor();

        }

        else if(s[i]=='/')

        {

            i++;

            x=x/factor();

        }

    }

    return x;

}

long factor()

{long x=0;

    if(s[i]=='(')

    {

        i++;

        x=eval();

        i++;

    }

    else

    {

        while(s[i]>='0'&&s[i]<='9')

        {

            x=x*10+s[i]-'0';

            i++;

        }

    }

    return x;

}



int main() {



f>>s;

g<<eval();





}
