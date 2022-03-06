#include <fstream>


using namespace std;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");



char s[100005], *p;



int termen();

int factor();



int eval()

{

   int rez=termen();

   while(*p == '+' || *p == '-')

   {

       if(*p=='+')

        p++,rez+=termen();

       else

        p++,rez-=termen();



   }

   return rez;

}



int termen()

{

    int rez=factor();

    while(*p=='*' || *p=='/')

    {

        if(*p=='*')

            p++, rez*=factor();

        else

            p++,rez/=factor();

    }

    return rez;

}



int factor()

{

    int rez=0;



    if(*p=='(')

        p++,rez= eval(),p++;

    else

    {

        while(isdigit(*p))

        {

            rez=rez*10+*p-'0';

            p++;

        }

    }

    return rez;



}

int main()

{

    cin >> s;

    p=s;

    cout<<eval();

}
