#include <fstream>


using namespace std;



char c[100000];

int i;



int solve();

int mult();

int num();



ifstream in ("evaluare.in");

ofstream out ("evaluare.out");



int solve()

{

    int t=mult();

    while(c[i]=='+' || c[i]=='-')

    {

        if(c[i]=='+')

        {

            i++;

            t+=mult();
        }

        else if(c[i]=='-')

        {

            i++;

            t-=mult();

        }

    }

    return t;

}



int mult()

{

    int t=num();

    while(c[i]=='*' || c[i]=='/')

    {

        if(c[i]=='*')

        {

            i++;

            t*=num();

        }

        else if(c[i]=='/')

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

    if(c[i]=='(')

    {

        i++;

        t=solve();

        i++;

    }

    else

    {

        while(isdigit(c[i]))

        {

            t=t*10+(int)c[i]-48;

            i++;

        }

    }

    return t;

}



int main()

{

    in.getline(c, 100000);

    out << solve();

    return 0;

}
