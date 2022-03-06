#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;

ifstream f ("evaluare.in");

ofstream g ("evaluare.out");

stack <int> nr;

stack <char> operatori;

int lungime;

char sir[100001];

int putere(char semn)

{

    if(semn == '+' || semn == '-')

        return 1;

    if(semn == '*' || semn == '/')

        return 2;

    return 0;

}

int compune_nr(int &indice)

{

    int nr = 0;

    while(indice<lungime && isdigit(sir[indice]))

    {

        nr = (sir[indice]-'0') + nr*10;

        indice++;

    }

    return nr;

}

int calc_dupa_semn(int nr1,int nr2,char op)

{



    if(op == '+')

        return nr1+nr2;

    if(op == '-')

        return nr2-nr1;

    if(op == '*')

        return nr1*nr2;

    if(op == '/')

        return nr2/nr1;

}

int calculeaza_si_da_push()

{

    char op = operatori.top();

    operatori.pop();

    int nr1 = nr.top();

    nr.pop();

    int nr2 = nr.top();

    nr.pop();

    nr.push(calc_dupa_semn(nr1,nr2,op));

}

int main()

{

    f.getline(sir,100001);

    lungime = strlen(sir);

    for(int i = 0; i<lungime; i++)

    {

        if(sir[i] == ' ')

            continue;

        if(sir[i] == '(')

        {

            operatori.push('(');

        }

        if(isdigit(sir[i]))

        {

            nr.push(compune_nr(i));

            if(i==lungime)

                break;

        }

        if(sir[i] == ')')

        {

            while(!operatori.empty() && operatori.top()!='(')

            {

                calculeaza_si_da_push();

            }

            operatori.pop();

        }

        if(!isdigit(sir[i]) && sir[i]!='(' && sir[i]!=')')

        {

            int putere_curent = putere(sir[i]);

            while(!operatori.empty() && putere_curent<= putere(operatori.top()) )

            {

                calculeaza_si_da_push();

            }

            operatori.push(sir[i]);

        }





    }

    while(!operatori.empty() && operatori.top()!= '(')

    {

        calculeaza_si_da_push();

    }

    g << nr.top();

}
