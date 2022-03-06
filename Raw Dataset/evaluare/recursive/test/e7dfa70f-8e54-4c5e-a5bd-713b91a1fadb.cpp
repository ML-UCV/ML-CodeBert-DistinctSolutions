#include <bits/stdc++.h>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

int n,i;

char s[100100];





int termen();

int factor();

int eval();





int termen()

{

    int sol=factor();

    while(i<n&&(s[i]=='+'||s[i]=='-'))

    {

        i++;

        if(s[i-1]=='+')sol=sol+factor();

        else if(s[i-1]=='-')sol=sol-factor();

    }

    return sol;

}





int factor()

{

    int sol=eval();

    while(i<n&&(s[i]=='*'||s[i]=='/'))

    {

        i++;

        if(s[i-1]=='*')sol=sol*eval();

        else if(s[i-1]=='/')sol=sol/eval();

    }

    return sol;

}





int eval()

{

    int sol;

    if(s[i]=='(')

    {

        i++;

        sol=termen();

        i++;

    }

    else

    {

        int nr=0;

        while(isdigit(s[i]))

        {

            nr=nr*10+(s[i]-'0');

            i++;

        }

        sol=nr;

    }

    return sol;

}





int main()

{

    f>>s;

    n=strlen(s);

    i=0;

    g<<termen();

    return 0;

}
