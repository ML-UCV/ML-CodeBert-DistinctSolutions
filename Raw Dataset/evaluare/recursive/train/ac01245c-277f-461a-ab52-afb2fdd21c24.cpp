#include <fstream>
#include <string>


using namespace std;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");



string sir;

int idx;



long long eval();

long long term();

long long factor();



int main()

{

    cin>>sir;



    cout<<eval();



    return 0;

}



long long eval()

{

    long long rsp=term();



    while(sir[idx]=='+' || sir[idx]=='-')

        switch(sir[idx])

        {

            case'+':

            {

                ++idx;

                rsp+=term();

                break;

            }

            case'-':

            {

                ++idx;

                rsp-=term();

                break;

            }

        }

    return rsp;

}



long long term()

{

    long long rsp=factor();



    while(sir[idx]=='*' || sir[idx]=='/')

        switch(sir[idx])

        {

            case'*':

            {

                ++idx;

                rsp*=factor();

                break;

            }

            case'/':

            {

                ++idx;

                rsp/=factor();

                break;

            }

        }

    return rsp;

}



long long factor()

{

    long long rsp=0;



    if(sir[idx]=='(')

    {

        ++idx;

        rsp=eval();

        ++idx;

    }

    else

    {

        while(sir[idx]>='0' && sir[idx]<='9')

        {

            rsp=rsp*10+sir[idx]-'0';

            ++idx;

        }

    }

    return rsp;

}
