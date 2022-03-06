#include <iostream>
#include <fstream>
using namespace std;

long long int sol, i;

int expresie();

int factor();

int termen();

char S[100010];

int main()

{

    ifstream fin ("evaluare.in");

    ofstream fout("evaluare.out");

    fin.get(S,1000001);

    sol=expresie();

    fout<<sol;

    return 0;

}

int expresie()

{

    int r=termen();

    while(S[i]=='+'||S[i]=='-')

        if(S[i]=='+')

        {

            i++;

            r=r+termen();

        }

        else

        {

            i++;

            r=r-termen();

        }

    return r;

}

int termen ()

{

    int r=factor();

    while(S[i]=='*'||S[i]=='/')

        if(S[i]=='*')

        {

            i++;

            r=r*factor();

        }

        else

        {

            i++;

            r=r/factor();

        }

    return r;

}

int factor()

{

    int r;

    if(S[i]=='(')

    {

        i++;

        r=expresie();

        i++;

    }

    else

    {

        r=0;

        while(S[i]>='0'&&S[i]<='9')

        {

            r=r*10+S[i]-'0';

            i++;

        }

    }

    return r;

}
