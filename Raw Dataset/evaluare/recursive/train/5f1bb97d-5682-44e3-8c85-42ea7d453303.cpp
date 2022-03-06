#include <bits/stdc++.h>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



char s[100100];

int afla_termen(),adunare(),inmultire();

int i,N;



int afla_termen()

{

    int termen;

    if(s[i]=='(')

    {

        i++;

        termen=adunare();

        i++;

    }

    else

    {

        termen=0;

        while('0'<=s[i] && s[i]<='9')

        {

            termen=termen*10+(s[i]-'0');

            i++;

        }

    }

    return termen;

}



int adunare()

{

    int suma=inmultire();

    while((s[i]=='+' || s[i]=='-') && i<N)

    {

        i++;

        if(s[i-1]=='+')suma+=inmultire();

        else suma-=inmultire();

    }

    return suma;

}



int inmultire()

{

    int prod=afla_termen();

    while((s[i]=='*' || s[i]=='/') && i<N)

    {

        i++;

        if(s[i-1]=='*')prod*=afla_termen();

        else prod/=afla_termen();

    }

    return prod;

}



int main()

{

    f>>s;

    N=strlen(s);i=0;

    g<<adunare();

    return 0;

}
