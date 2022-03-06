#include <fstream>
#include <string>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

int p=0;

string s;

int termen();

int factor();

int evaluare(){

    long long int r=termen();

    while (s[p]=='+' || s[p]=='-'){

        switch (s[p]){

            case '+':

                p++;

                r+=termen();

                break;

            case '-':

                p++;

                r-=termen();

                break;

        }

    }

    return r;

}

int termen(){

    long long int r=factor();

    while (s[p]=='*' || s[p]=='/'){

        switch (s[p]){

            case '*':

                p++;

                r*=factor();

                break;

            case '/':

                p++;

                r/=factor();

                break;

        }

    }

    return r;

}

int factor(){

    long long int r=0;

    if (s[p]=='('){

            ++p;

            r=evaluare();

            p++;

        }

    else

    {

        while (s[p]>='0' && s[p]<='9')

        {

            r=r*10+s[p]-'0';

            p++;

        }

    }

    return r;

}

int main()

{

    fin>>s;

    fout<<evaluare();

    return 0;

}
