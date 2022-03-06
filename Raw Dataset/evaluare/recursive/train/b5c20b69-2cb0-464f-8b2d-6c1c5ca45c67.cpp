#include <bits/stdc++.h>


using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int p;

string s;

int factor();

int termen();

int evaluare()

{

    int r=factor();

    while(s[p]=='+' || s[p]=='-')

    {

        p++;

        if(s[p-1]=='+') r+=factor();

        else r-=factor();

    }

    return r;

}



int factor()

{

    int r=termen();

    while(s[p]=='*' || s[p]=='/')

    {

        p++;

        if(s[p-1]=='*') r*=termen();

        else r/=termen();

    }

    return r;

}

int termen()

{

    int r=0;

    if(s[p]=='(')

    {

     p++;

     r=evaluare();

     ++p;

    }

    else while(s[p]>='0'&& s[p]<='9') {r=r*10+(s[p]-'0'); p++;

    }

    return r;

}

int main()

{

    fin>>s;

    s+='#';

    fout<<evaluare();

    return 0;

}
