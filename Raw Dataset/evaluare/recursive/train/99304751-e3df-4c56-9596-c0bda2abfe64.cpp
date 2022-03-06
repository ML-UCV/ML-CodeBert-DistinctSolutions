#include <fstream>


using namespace std;

ifstream cin("evaluare.in");

ofstream cout("evaluare.out");

char S[100100], *p=S;



long long eval();



long long termen();



long long factor();



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cin>>S;

    cout<<eval()<<'\n';

    return 0;

}



long long eval()

{

    long long r=termen();

    while(*p=='+' || *p=='-')

    {

        if(*p=='+'){

            ++p;

            r+=termen();

        }

        else{

            ++p;

            r-=termen();

        }

    }

    return r;

}



long long termen()

{

    long long r=factor();

    while(*p=='*'||*p=='/')

    {

        if(*p=='*'){

            ++p;

            r*=factor();

        }

        else{

            ++p;

            r/=factor();

        }

    }

    return r;

}



long long factor()

{

    long long r=0;

    if(*p=='(')

    {

        ++p;

        r=eval();

        ++p;

    }

    else while(isdigit(*p))

    {

        r=r*10+(*p-'0');

        ++p;

    }

    return r;

}
