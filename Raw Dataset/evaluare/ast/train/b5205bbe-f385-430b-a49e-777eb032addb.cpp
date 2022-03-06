#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;



const int MAXN = 100041;

char sir[MAXN];

int par[MAXN];



struct Nod

{

    int val;

    char op;

    Nod *st, *dr;

    Nod(char _op, Nod* _st, Nod* _dr) {

        op = _op;

        st = _st;

        dr = _dr;

    }

    Nod(int _val) {

        val = _val;

        op = '?';

        st = dr = nullptr;

    }

};



int form_par(int ind = 0)

{

    for(int i = ind; sir[i]; i++)

        if(sir[i] == '(') {

            int res = form_par(i+1);

            par[res] = i;

            i = res;

        }

        else if(sir[i] == ')')

            return i;

}



Nod* construct(int st, int dr, int level)

{

    if (level == 0) {

        for (int i = dr; i >= st; i--)

        if (sir[i] == ')') i = par[i];

        else if (sir[i] == '+' || sir[i] == '-')

            return new Nod(sir[i], construct(st, i-1, level), construct(i+1, dr, level+1));

    }

    for (int i = dr; i >= st; i--)

        if (sir[i] == ')') i = par[i];

        else if (sir[i] == '*' || sir[i] == '/')

            return new Nod(sir[i], construct(st, i-1, 1), construct(i+1, dr, 1));

    if (sir[st] == '(')

        return construct(st+1, dr-1, 0);

    int nr = 0;

    for (int i = st; i <= dr; i++)

        nr = nr*10 + sir[i] - '0';

    return new Nod(nr);

}



int eval(Nod* root)

{

    if (root->op == '?')

        return root->val;

    int x = eval(root->st);

    int y = eval(root->dr);

    switch (root->op) {

        case '+': return x+y;

        case '-': return x-y;

        case '*': return x*y;

        case '/': return x/y;

    }

}



int main()

{

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");



    fin >> sir;

    form_par(0);

    Nod* root = construct(0, strlen(sir)-1, 0);

    fout << eval(root);





    return 0;

}
