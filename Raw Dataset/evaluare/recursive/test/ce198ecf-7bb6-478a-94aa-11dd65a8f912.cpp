#include <bits/stdc++.h>
using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char s[100005],c;

int poz;



int adun();



int termen()

{

    int rez=0;

    if(c=='(')

    {

        poz++;

        c=s[poz];

        rez=adun();

        poz++;

        c=s[poz];

    }

    else

        while(c>='0'&&c<='9')

    {

        rez=rez*10+(c-'0');

        poz++;

        c=s[poz];

    }

    return rez;

}



int prod()

{

    int rez=termen();

    while(c=='*'||c=='/')

    {

         if(c=='*')

        {

            poz++;

            c=s[poz];

            rez*=termen();

        }

        else

        {

            poz++;

            c=s[poz];

            rez/=termen();

        }

    }

    return rez;

}



int adun()

{

    int rez=prod();

    while(c=='+'||c=='-')

    {

        if(c=='+')

        {

            poz++;

            c=s[poz];

            rez+=prod();

        }

        else

        {

            poz++;

            c=s[poz];

            rez-=prod();

        }

    }

    return rez;

}



int main()

{

    fin.getline(s,100000);

    c=s[poz];

    fout<<adun();

    return 0;

}
