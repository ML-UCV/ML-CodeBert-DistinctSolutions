#include <fstream>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



const int N=100003;

char s[N];

int p;



int expresie();

int termen();

int factor();



int expresie()

{

    int sum=termen();

    while(s[p]=='+'||s[p]=='-')

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

    while(s[p]=='*'||s[p]=='/')

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

        return val*semn;

    }

    while(s[p]>='0'&&s[p]<='9')

    {

        val=val*10+s[p]-48;

        p++;

    }

    return val*semn;

}



int main()

{

    fin.getline(s,100001);

    fout<<expresie();

    return 0;

}
