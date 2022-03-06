#include <fstream>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

char s[100001];



long termen();

long factor();

int i;
long eval()

{

    long r;

    r= termen();

    while (s[i]=='+' || s[i]=='-')



        switch(s[i])

        {

        case '+':

            i++;

            r=r+termen();

            break;

        case '-':

            i++;

            r=r-termen();

            break;

        }

    return r;

}
long termen()

{

    long r;

    r=factor();

    while (s[i]=='*' || s[i]=='/')

        switch(s[i])

        {

            case '*':i++;

                     r=r*factor();

                      break;



            case '/': i++;

                      r=r/factor();

                      break;

        }

    return r;

}
long factor()

{

    long r;

    r=0;

    if(s[i]=='(')

    {

        i++;

        r=eval();

        i++;

    }

    else

            while(s[i]>='0' && s[i]<='9')

            {

                r=r*10+s[i]-'0';

                i++;

            }

return r;

}

    int main()

    {

        char x;

        i=0;

        while (fin>>x)

        {

            i++;

            s[i]=x;

        }



        i=1;

        fout<<eval();

        return 0;

    }
