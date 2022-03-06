#include <bits/stdc++.h>
using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");



int E(),T(),F(),N();char c;

int main()

{

    g<<E();

    return 0;

}

int E()

{

    f>>c;

    int R=T();

    while(c=='+'||c=='-')

        if(c=='+')

        {

            f>>c;

            R+=T();

        }

        else

        {

            f>>c;

            R-=T();

        }

    return R;

}

int T()

{

    int R=F();

    while(c=='*'||c=='/')

        if(c=='*')

        {

            f>>c;

            R*=F();

        }

        else

        {

            f>>c;

            R/=F();

        }

    return R;

}

int F()

{

    if(isdigit(c))

    return N();

    int R=E();

    f>>c;

    return R;

}

int N()

{

    int R=0;

    while(isdigit(c))

    {

        R=10*R+c-'0';

        if(!(f>>c))c=0;;

    }

    return R;

}
