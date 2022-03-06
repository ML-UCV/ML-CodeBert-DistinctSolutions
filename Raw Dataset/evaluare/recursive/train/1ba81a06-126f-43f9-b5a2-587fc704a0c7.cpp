#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");







char e[100005];



int i,lg;



int evalexp();

int evaltermen();

int evalfactor();



int evalexp()

{

    int f=evaltermen();



    char sgn;



    while(i<lg && (e[i] == '+' || e[i] == '-'))

          {

              sgn=e[i];



              i++;



              if(sgn == '-')

                 f=f-evaltermen();

              else

                 f=f+evaltermen();



          }

    return f;

}



int evaltermen()

{

    int f=evalfactor();



    char sgn;



    while( i <lg && ( e[i] == '*' || e[i] == '/'))

        {

            sgn=e[i];



            i++;



            if(sgn == '*')

                f=f*evalfactor();

            else

                f=f/evalfactor();

        }

    return f;

}



int numar()

{

    int nr=0;



    while( e[i] >='0' && e[i] <='9')

        {

            nr=nr*10+(e[i]-'0');

            i++;

        }



    return nr;



}



int evalfactor()

{

    int f=0;



    if( e[i] == '(')

    {

        i++;

        f=f+evalexp();

        i++;



    }

    else

        f=numar();

    return f;

}



int main()

{

    fin>>e;



    lg=strlen(e);



    fout<<evalexp();





    return 0;

}
