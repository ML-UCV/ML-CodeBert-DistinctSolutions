#include <fstream>
#include <cstring>


using namespace std;



ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");

const int MAXN=100000;

char sir[MAXN];

struct Nod

{

    Nod *st, *dr;

    int val;

    char op;

    Nod(char _op, Nod *_st, Nod *_dr)

    {

        op=_op;

        st=_st;

        dr=_dr;

    }

};

Nod* construct (int st, int dr)

{

    int par=0;

    for(int i=dr; i>=st; i--)

    {

        if(sir[i]==')') par++;

        else if(sir[i]=='(') par--;

        else if(par==0 && (sir[i]=='+' || sir[i]=='-'))

            return new Nod(sir[i], construct(st, i-1), construct(i+1, dr));

    }

    par=0;

    for(int i=dr; i>=st; i--)

    {

        if(sir[i]==')') par++;

        else if(sir[i]=='(') par--;

        else if(par==0 && (sir[i]=='*' || sir[i]=='/'))

            return new Nod(sir[i], construct(st, i-1), construct(i+1, dr));

    }

    if(sir[st]=='(') return construct(st+1, dr-1);

    int nr=0;

    for(int i=st; i<=dr; i++)

        nr=nr*10+sir[i]-'0';

    Nod*rez=new Nod ('?', nullptr, nullptr);

    rez->val=nr;

    return rez;

}

int eval (Nod* root)

{

    if(root->op == '?')

        return root->val;

    int x=eval(root->st);

    int y=eval(root->dr);

    switch(root->op){

        case '+': return x+y;

        case '-': return x-y;

        case '*': return x*y;

        case '/': return x/y;

    }

}

int main()

{

    fin>>sir;

    Nod* root = construct (0, strlen(sir)-1);

    fout<<eval(root);

    return 0;

}
