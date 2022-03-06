#include <bits/stdc++.h>
using namespace std;

ifstream fin ("evaluare.in");

ofstream fout("evaluare.out");

char s[100002];

int poz;



long long termen();



long long sum();



long long prod();





long long termen()

{

    long long rez=0;

    if (s[poz]=='(')

    {

        poz++;

        rez=sum();

        poz++;

    }

    else

    while (s[poz]<='9' && s[poz]>='0')

        rez=rez*10+(s[poz++]-'0');

    return rez;

}



long long prod ()

{

    long long rez=termen();

    while (s[poz]=='*' || s[poz]== '/')

    {

        if (s[poz]=='*')

        {

            poz++;

        rez*= termen();

        }

        else

        {

            poz++;

            rez/=termen();

        }

    }

    return rez;

}





long long sum ()

{

    long long rez=prod();

    while (s[poz]=='+' || s[poz]=='-')

    {

        if (s[poz]=='+')

        {

            poz++;

            rez+=prod();

        }

        else

        {

            poz++;

            rez-=prod();

        }

    }

    return rez;

}



int main()

{

    fin.getline(s,100002);

    fout<<sum();

    return 0;

}
