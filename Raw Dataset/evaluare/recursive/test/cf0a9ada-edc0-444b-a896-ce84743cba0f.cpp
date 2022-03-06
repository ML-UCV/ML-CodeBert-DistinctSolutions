#include <fstream>
#include <cstring>
using namespace std;



char S[100010],*p=S;

int eval2();

int calcul();



int eval1() {

 int r = eval2();

  while (*p=='+'||*p=='-')

        {

  if (*p=='+')

  {

   p++;

   r+=eval2();

  }

        else if (*p=='-')

        {

            p++;

            r-=eval2();

        }

 }

 return r;

}



int eval2()

{

 int r = calcul();

 while(*p=='*'||*p=='/')

        {

  if(*p=='*')

            {

                p++;

    r*=calcul();

            }

        else if (*p=='/')

   {

    p++;

    r/=calcul();

   }

  }

 return r;

}



int calcul() {

    int r=0;

    if (*p=='(')

    {

        p++;

  r=eval1();

  p++;

    }

    else

    {

        while (*p>='0'&&*p<='9')

        {

            r=r*10+*p-'0';

   p++;

  }

    }

    return r;

}



int main()

{

    ifstream f("evaluare.in");

    ofstream fout("evaluare.out");

    f.getline(S,100010);

    fout<<eval1();

    return 0;

}
