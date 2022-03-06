#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



string s;



int termen(int&);

int expresie(int&);

int factor(int&);

int numar(int&);



int expresie(int &p)

{

    int r=termen(p);

    while(s[p]=='+' or s[p]=='-')

    {

        p++;

        if(s[p-1]=='+') r+=termen(p);

        else r-=termen(p);

    }

    return r;

}



int termen(int &p)

{

    int r=factor(p);

    while(s[p]=='/' or s[p]=='*')

    {

        p++;

        if(s[p-1]=='*') r*=factor(p);

        else r/=factor(p);

    }

    return r;

}



int factor(int &p)

{

    int r=0;

    if(s[p]=='(')

    {

        p++;

        r=expresie(p);

        if(s[p]==')') p++;

    }

    else r=numar(p);

    return r;

}



int numar(int &p)

{

    int nr=0;

    while(s[p]>='0' and s[p]<='9')

    {

        nr*=10;

        nr+=(s[p]-'0');

        p++;

    }

    return nr;

}



int main()

{

    fin >> s;

    int p=0;

    fout << expresie(p);

    return 0;

}
