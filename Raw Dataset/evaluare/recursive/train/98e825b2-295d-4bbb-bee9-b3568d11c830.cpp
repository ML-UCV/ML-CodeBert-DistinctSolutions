#include <iostream>
#include <fstream>


using namespace std;



ifstream fi("evaluare.in");

ofstream fo("evaluare.out");



char s[1000010];

char *p=s;



long int termen();

long int factor();



long int eval()

{

    long int r=termen();



    while(*p=='+'||*p=='-')

        switch(*p){

            case '+':

                ++p;

                r += termen();

                break;

            case '-':

                ++p;

                r -= termen();

                break;

        }



    return r;

}



long int termen()

{

    long int r=factor();



    while(*p=='*'||*p=='/')

        switch(*p){

            case '*':

                ++p;

                r *= factor();

                break;

            case '/':

                ++p;

                r /= factor();

                break;

        }



    return r;

}



long int factor()

{

    long int r=0;



    if( *p=='(' )

        {++p;

        r = eval();

        ++p;}

    else

    {

        while(*p>='0'&&*p<='9')

            {r = r*10 + *p - '0';

            ++p;}

    }



    return r;

}



int main()

{

    fi>>s;



    fo<<eval();



    return 0;

}
