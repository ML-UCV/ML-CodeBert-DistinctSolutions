#include <bits/stdc++.h>


using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

int grad1(),grad2(),grad3();







char s[100005];

int i;

int grad1()

{

    int r=grad2();

    while(s[i]=='+'||s[i]=='-')

    {

        i++;

        if(s[i-1]=='-')

            r-=grad2();

        else

            r+=grad2();

    }

    return r;

}

int grad2()

{

    int r=grad3();

    while(s[i]=='*'||s[i]=='/')

    {

        i++;

        if(s[i-1]=='*')

            r*=grad3();

        else

            r/=grad3();

    }

    return r;

}

int grad3()

{

    int r=0;

    if(s[i]=='(')

    {

        i++;

        r=grad1();

        i++;

        return r;

    }

    while(s[i]>='0'&&s[i]<='9')

    {

        r=r*10+s[i]-'0';

        i++;

    }

    return r;

}

int main()

{

    fin>>s;

    i=0;

    fout<<grad1();

}
