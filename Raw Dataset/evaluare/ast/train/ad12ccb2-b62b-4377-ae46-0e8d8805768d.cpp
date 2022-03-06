#include <fstream>
#include <cstring>




using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



struct nod

{

    int val;

    char op;

    nod *st, *dr;



    nod(int a=0, char b=0, nod*c=0, nod*d=0)

    {

        val = a;

        op = b;

        st = c;

        dr = d;

    }

};



char prio[3][3] = { "+-", "*/", "" };



nod* arbore(int k);

int eval(nod*A);

void inordine(nod*x)

{

    if (x->st)

        inordine(x->st);

    if (x->val)

        fout << x->val;

    else fout << x->op;

    if (x->dr)

        inordine(x->dr);

}



int poz, n;

char s[100005];

nod*A;



int main()

{

    fin >> s;

    n = strlen(s);

    A = arbore(0);



    fout << eval(A) << '\n';

    return 0;

}



nod* arbore(int k)

{

    nod *x, *y;

    if (k == 2)

    {

        if (s[poz] == '(')

        {

            poz++;

            x = arbore(0);

            poz++;

        }

        else

        {

            x = new nod();

            while (s[poz] <= '9' && s[poz] >= '0')

            {

                x->val = x->val*10+s[poz]-'0';

                poz++;

            }

        }

    }

    else

    {

        x = arbore(k+1);

        while (poz < n && strchr(prio[k],s[poz]))

        {

            y = new nod(0,s[poz++],x,arbore(k+1));

            x = y;

        }

    }

    return x;

}



int eval(nod*A)

{

    switch (A->op)

    {

        case '+': return eval(A->st) + eval(A->dr); break;

        case '-': return eval(A->st) - eval(A->dr); break;

        case '*': return eval(A->st) * eval(A->dr); break;

        case '/': return eval(A->st) / eval(A->dr); break;

        default: return A->val;

    }

}
