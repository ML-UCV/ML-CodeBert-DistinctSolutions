#include <fstream>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

char s[1000010];

int n,i,nr;

int eval();

int factor();

int termen();

int eval()

{

    int r=termen();

    while(s[nr]=='+' || s[nr]=='-')

    {

        if(s[nr]=='+')

        {

            nr++;

            r+=termen();

        }

        else

        {

            nr++;

            r-=termen();

        }

    }

    return r;

}

int termen()

{

    int r=factor();

    while(s[nr]=='*' || s[nr]=='/')

    {

        if(s[nr]=='*')

        {

            nr++;

            r*=factor();

        }

        else

        {

            nr++;

            r/=factor();

        }

    }

    return r;

}

int factor()

{

    int r=0;

    if(s[nr]=='(')

    {

        nr++;

        r=eval();

        nr++;

    }

    while(s[nr]>='0' && s[nr]<='9')

    {

        r=r*10+(s[nr]-'0');

        nr++;

    }

    return r;

}

int main()

{

    f.getline(s,1000010);

    nr=0;

    g<<eval()<<'\n';

    return 0;

}
