#include <fstream>


using namespace std;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");



const int N = 1e5+1;

char text[N];

int index = 0;



int expresie();

int termen();

int factor();



int expresie()

{

    int sum = termen();

    while(text[index]=='+' || text[index]=='-')

    {

        if(text[index]=='+')

        {

            ++index;

            sum+=termen();

        }

        else

        {

            ++index;

            sum-=termen();

        }

    }

    return sum;

}



int termen()

{

    int prod = factor();

    while(text[index]=='*' || text[index]=='/')

    {

        if(text[index]=='*')

        {

            ++index;

            prod*=factor();

        }

        else

        {

            ++index;

            prod/=factor();

        }

    }

    return prod;

}



int factor()

{

    int val = 0,semn = 1;

    while(text[index]=='-')

    {

        ++index;

        semn*=-1;

    }

    if(text[index]=='(')

    {

        ++index;

        val = expresie();

        ++index;

        return val*semn;

    }

    while(isdigit(text[index]))

    {

        val=val*10+(text[index]-'0');

        ++index;

    }

    return semn*val;

}



int main()

{

    cin.getline(text,N);

    cout<<expresie();

    return 0;

}
