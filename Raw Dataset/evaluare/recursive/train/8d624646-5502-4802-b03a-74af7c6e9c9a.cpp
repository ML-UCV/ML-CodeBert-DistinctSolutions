#include <cstdio>
#include <cstring>
#include <cctype>




using namespace std;



FILE *fin=freopen("evaluare.in","r",stdin);

FILE *fout=freopen("evaluare.out","w",stdout);



char s[100005];

int i=0;



int num();

int mult();



int solve()

{

    long t=mult();

    while(s[i]=='+' || s[i]=='-')

    {

        if(s[i]=='+')

        {

            i++;

            t+=mult();

        }

        else

        {

            i++;

            t-=mult();

        }

    }

    return t;

}



int mult()

{

    long t=num();

    while(s[i]=='*' || s[i]=='/')

    {

        if(s[i]=='*')

        {

            i++;

            t*=num();

        }

        else

        {

            i++;

            t/=num();

        }

    }

    return t;

}



int num()

{

    int t=0;

    if(s[i]=='(')

    {

        i++;

        t=solve();

        i++;

    }

    else

        while(isdigit(s[i]))

        {

            t=t*10+s[i++]-'0';

        }

    return t;

}



void citire()

{

    fgets(s,100005,stdin);

}



int main()

{

    citire();

    printf("%d\n",solve());

    return 0;

}
