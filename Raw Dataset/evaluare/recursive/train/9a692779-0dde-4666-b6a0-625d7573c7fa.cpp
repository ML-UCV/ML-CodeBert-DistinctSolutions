#include <fstream>
#include <cstring>
using namespace std;

ifstream cin("evaluare.in");

ofstream cout("evaluare.out");

char c[100005];

int ind;

int fact(),exp(),pol();

int exp()

{

    int t=fact();

    while(c[ind]=='+'||c[ind]=='-')

    { ++ind;

        if(c[ind-1]=='+')

            t+=fact();

            else

        t-=fact();

    }

    return t;

}

int fact()

{

    int t=pol();

    while(c[ind]=='*'||c[ind]=='/')

    {

        ind++;

        if(c[ind-1]=='*') t*=pol();

        else

            t/=pol();

    }

    return t;

}

int pol()

{ int t=0;

    if(c[ind]=='(')

    { ++ind;

       t=exp();

       ++ind;

       return t;

    }

    else

    {

    while(isdigit(c[ind]))

       {

          t=t*10+c[ind]-'0';

          ++ind;

       }

    }

    return t;

}

int main()

{

    cin>>(c+1);

    int x=strlen(c)-1;

    ind=1;

    cout<<exp();

    return 0;

}
