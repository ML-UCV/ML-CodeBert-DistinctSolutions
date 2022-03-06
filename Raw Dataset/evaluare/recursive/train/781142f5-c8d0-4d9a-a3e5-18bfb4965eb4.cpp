#include<fstream>
using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

char s[100002];

int i;



int termen();

int factor();



int calc()

{

    int x=termen();

    while(s[i]=='+'||s[i]=='-')

    {

        if(s[i]=='+')

        {

            i++;

            x+=termen();

        }

        else

        {

            i++;

            x-=termen();

        }

    }

    i++;

    return x;

}



int termen()

{

    int x=factor();

    while(s[i]=='*'||s[i]=='/')

    {

        if(s[i]=='*')

        {

            i++;

            x*=factor();

        }

        else

        {

            i++;

            x/=factor();

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

        while(s[i]>='0'&&s[i]<='9')

        {

            x*=10;

            x+=s[i]-48;

            i++;

        }

        return x;

    }

}



int main()

{

    int sol;

    f.getline(s+1,100001);

    i=1;

    sol=calc();

    g<<sol;

    return 0;

}
