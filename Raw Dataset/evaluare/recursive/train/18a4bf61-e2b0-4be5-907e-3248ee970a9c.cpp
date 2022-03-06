#include <stdio.h>
#include <string.h>


using namespace std;



FILE *fin = fopen("evaluare.in", "r");

FILE *fout = fopen("evaluare.out", "w");



int n;

char sir[100005],*p;



int eval();

int termen();

int factor();



int main()

{

    fgets(sir, 100002, fin);

    n = strlen(sir)-1;



    p = sir;

    fprintf(fout, "%d", eval());



    fclose(fin);

    fclose(fout);

    return 0;

}



int factor()

{

    int r;



    if(*p == '(')

    {

        ++p;

        r = eval();

        ++p;

    }

    else

    {

        r = 0;

        while(*p>='0' and *p<='9')

        {

            r = r*10+(*p-'0');

            ++p;

        }

    }

    return r;

}



int termen()

{

    int ans;



    ans = factor();

    while(*p == '*' or *p == '/')

        if(*p == '*')

        {

            ++p;

            ans *= factor();

        }

        else

        {

            ++p;

            ans /= factor();

        }



    return ans;

}



int eval()

{

    int ans;



    ans = termen();

    while(*p == '+' or *p == '-')

        if(*p == '+')

        {

            ++p;

            ans += termen();

        }

        else

        {

            ++p;

            ans -= termen();

        }



    return ans;

}
