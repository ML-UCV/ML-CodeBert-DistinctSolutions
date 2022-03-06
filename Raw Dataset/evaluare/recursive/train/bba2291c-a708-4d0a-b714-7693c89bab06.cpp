#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f ("evaluare.in");

ofstream g ("evaluare.out");

char sir[100001];

int lungime;

int compune_nr(int indice)

{

    int nr = 0;

    while(indice<lungime && isdigit(sir[indice]))

    {

        nr = (sir[indice]-'0') + nr*10;

        indice++;

    }

    return nr;

}

int eval_expr(int st,int dr)

{

    int paranteze = 0;



    for(int i = dr;i>=st;i--)

    {

        if(sir[i] == ')')

            paranteze++;

        else

        if(sir[i] == '(')

            paranteze--;

        else

        if(sir[i] == '+' && paranteze == 0)

            return eval_expr(st,i-1) + eval_expr(i+1,dr);

        if(sir[i] == '-' && paranteze == 0)

            return eval_expr(st,i-1) - eval_expr(i+1,dr);

    }

    paranteze = 0;



    for(int i = dr;i>=st;i--)

    {

        if(sir[i] == ')')

            paranteze++;

        if(sir[i] == '(')

            paranteze--;

        if(sir[i] == '*' && paranteze == 0)

            return eval_expr(st,i-1) * eval_expr(i+1,dr);

        if(sir[i] == '/' && paranteze == 0)

            return eval_expr(st,i-1) / eval_expr(i+1,dr);

    }



    if(sir[st] == '(' && sir[dr] == ')')

        return eval_expr(st+1,dr-1);



    return compune_nr(st);

}

int main()

{

    f.getline(sir,100001);

    lungime = strlen(sir);

    g << eval_expr(0,lungime-1);

}
