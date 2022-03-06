#include <cstdio>
const long MAX = 100010;



char s[MAX];

int i = 0;







long termen();



long factor();
long eval()

{

    long rezultat = termen();

    while ( s[i] =='+' || s[i]=='-' )

    {

        switch ( s[i] )

        {

        case '+':

            ++i;

            rezultat += termen();

            break;

        case '-':

            ++i;

            rezultat -= termen();

            break;

        }

    }

    return rezultat;

}
long termen()

{

    long rezultat=factor();

    while ( s[i] =='*' || s[i]=='/' )

    {

        switch ( s[i] )

        {

        case '*':

            ++i;

            rezultat *= factor();

            break;

        case '/':

            ++i;

            rezultat /= factor();

            break;

        }

    }

    return rezultat;

}
long factor()

{

    long f=0;

    if(s[i]=='(')

        {

            i++;

            f=eval();

            i++;

        }

    while(s[i]>='0' && s[i]<='9')

    {

        f*=10;

        f+=s[i]-'0';

        i++;

    }

    return f;

}







int main()

{



    fgets(s, MAX, fopen("evaluare.in", "r"));

    fprintf(fopen("evaluare.out", "w"), "%ld\n", eval());

    return 0;

}
