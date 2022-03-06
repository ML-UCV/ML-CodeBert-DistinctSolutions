#include <fstream>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

int n,i;

char s[100005];

long fact();

long termen();

long eval()

{

    long r=termen();

    while(s[i]=='+'||s[i]=='-')

    {



        if(s[i]=='+') {i++;r+=termen();}

        else {i++;r-=termen();}

    }

    return r;

}

long termen()

{

    long r=fact();

    while(s[i]=='*'||s[i]=='/')

    {

        if(s[i]=='*') {i++;r=r*fact();}

        else {i++;r=r/fact();}

    }

    return r;

}

long fact()

{

    long r=0;

    if(s[i]=='(') {i++;r=eval();i++;}

    else

    {

        while(s[i]>='0'&&s[i]<='9')

        {

            r=r*10+s[i]-'0';

            i++;

        }

    }

    return r;

}

int main()

{

    f>>s;

    g<<eval();

    return 0;

}
