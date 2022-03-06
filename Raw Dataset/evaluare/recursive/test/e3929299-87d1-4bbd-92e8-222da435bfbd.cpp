#include <iostream>
#include <fstream>


using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



const int N=100001;



char s[N];



int p;

int expresie();

int termen();

int factor();



int expresie()

{

    int sum=termen();

    while (s[p] == '+' || s[p] == '-')

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

    while(s[p]== '*' || s[p] == '/')

    {

        if (s[p] == '*')

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

        p++;

        semn=-semn;

    }

    if(s[p]=='(')

    {

        p++;

        val=expresie();

        p++;

        return semn*val;

    }

    while('0'<=s[p]&&s[p]<='9')

    {

        val=val*10+(s[p]-'0');

        p++;

    }

    return semn*val;

}



int main()

{

    in>>s;

    out<<expresie();

    return 0;

}
