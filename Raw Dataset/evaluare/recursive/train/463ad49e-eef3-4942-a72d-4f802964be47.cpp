#include <bits/stdc++.h>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

int Expresie();

int Termen();

int Factor();

char S[100007];

int indexxx;



int Expresie()

{

    int r=Termen();

    while(S[indexxx]=='+'||S[indexxx]=='-')

    {

        indexxx++;

        if(S[indexxx-1]=='+') r+=Termen();

        else r-=Termen();

    }

    return r;

}



int Termen()

{

    int r=Factor();

    while(S[indexxx]=='/'||S[indexxx]=='*')

    {

        indexxx++;

        if(S[indexxx-1]=='/') r/=Factor();

        else r*=Factor();

    }

    return r;

}



int Factor()

{

    int sgn=1;

    while(S[indexxx]=='-') sgn=-sgn,indexxx++;



    if(S[indexxx]=='(')

    {

        indexxx++;

        int r=Expresie();

        indexxx++;

        return r*sgn;

    }

    int r=0;



    while(S[indexxx]>='0'&&S[indexxx]<='9')

    r=r*10+(S[indexxx]-'0'),indexxx++;



    return r;

}



int main()

{

    f>>(S+0);

    g<<Expresie();



    return 0;

}
