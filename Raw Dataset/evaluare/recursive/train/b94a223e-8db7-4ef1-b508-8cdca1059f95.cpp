#include <fstream>
using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



char s[100005];

int p;

int expresie();

int termen();

int factor();



int expresie()

{

    int sum=termen();

    while(s[p]=='+' || s[p]=='-')

    {

        if(s[p]=='+')

        {

            p++;

            sum+=termen();

        }

        else

        {

            p++;

            sum-=termen();

        }

    }

    return sum;

}



int termen()

{

    int prod=factor();

    while(s[p]=='*' || s[p]=='/')

    {

        if(s[p]=='*')

        {

            p++;

            prod*=factor();

        }

        else

        {

            p++;

            prod/=factor();

        }

    }

    return prod;

}



int factor()

{

    int val=0,semn=1;

    while(s[p]=='-')

    {

        semn=-semn;

        p++;

    }

    if(s[p]=='(')

    {

        p++;

        val=expresie();

        p++;

        return semn*val;

    }

    while(s[p]>='0' && s[p]<='9')

    {

        val=val*10+s[p++]-'0';

    }

    return semn*val;

}



int main()

{

    in>>s;

    out<<expresie();

    return 0;

}
