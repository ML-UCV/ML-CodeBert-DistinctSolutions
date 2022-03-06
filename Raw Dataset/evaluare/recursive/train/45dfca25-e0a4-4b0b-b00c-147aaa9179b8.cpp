#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int EvaluareTermen();

int EvaluareFactor();

int EvaluareExpresie();

int eval();



char e[100005];

int lg,i;



int eval()

{

    int nr=0;

    while(e[i]<='9' && e[i]>='0') nr=nr*10+e[i]-'0',i++;



    i--;

    return nr;



}

int EvaluareFactor()

{

    int f;

    if(e[i]=='(')

    {

        i++;

        f=EvaluareExpresie();



        i++;

    }

    else f=eval(),i++;



    return f;

}

int EvaluareTermen()

{

    int f=EvaluareFactor();

    while(i<lg && (e[i]=='*' || e[i]=='/'))

    {

        i++;

        if(e[i-1]=='*') f*=EvaluareFactor();

        else f/=EvaluareFactor();

    }

    return f;

}



int EvaluareExpresie()

{

    int f=EvaluareTermen();

    while(i<lg && (e[i]=='+' || e[i]=='-') )

    {

        i++;

        if(e[i-1]=='+') f+=EvaluareTermen();

        else f-=EvaluareTermen();



    }

    return f;



}



int main()

{

    fin>>e;

    lg=strlen(e);

    fout<<EvaluareExpresie();



    return 0;

}
