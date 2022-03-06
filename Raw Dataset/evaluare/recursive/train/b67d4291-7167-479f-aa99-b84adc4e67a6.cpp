#include <iostream>
#include<fstream>
#include<cstring>
#include<algorithm>


using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

int lg,i;

char e[100005];



int formareNr();

int Expresie();

int Termen();

int Factor();



int FormareNr()

{ int nr=0;

    while(e[i]>='0' && e[i]<='9' && i<lg)

          {

              nr=nr*10+e[i]-'0';

              i++;

          }



    return nr;

}



int Factor()

{

    int f;



    if(e[i]=='(')

    {

        i++;

        f=Expresie();

        i++;

        return f;

    }



    else {int nr=0;

          while(i<lg&&e[i]>='0'&&e[i]<='9')

                {

                  nr=nr*10+e[i]-'0';

                  i++;

                }

           return nr;

         }

}



int Termen()

{

    int f=Factor();



    while(i<lg && (e[i]=='*' || e[i]=='/'))

          {

              char op=e[i];

               i++;

               if(op=='*') f=f*Factor();

               else f=f/Factor();



          }

    return f;

}



int Expresie()

{

    int f=Termen();



    while(i<lg && (e[i]=='+' || e[i]=='-'))

    {

        char op=e[i];

        i++;

        if(op=='+') f=f+Termen();

        else f=f-Termen();

    }



    return f;

}

int main()

{

    fin>>e;

    lg=strlen(e);

    fout<<Expresie();

    return 0;

}
