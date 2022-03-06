#include <fstream>
#include <cstring>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



char a[100005];

char semne[100005];

int nre[100005];

int top_semne, top_nre;

int l;



bool isDigit(char a)

{

    if(a >= '0' && a <= '9')

        return 1;

    return 0;

}



void push_semne(char semn)

{

    semne[++top_semne] = semn;

}



void push_nre(int nr)

{

    nre[++top_nre] = nr;

}



void formnr(int &i)

{

    int nr = 0;

    while(isDigit(a[i]))

    {

        nr = nr * 10 + (a[i] - '0');

        ++i;

    }

    --i;

    push_nre(nr);

}



void calcul(char c)

{

    int x = nre[top_nre];

    nre[top_nre --] = 0;

    int y = nre[top_nre];

    nre[top_nre --] = 0;

    int rez;



    switch(c)

    {

        case '+':

            rez = y + x;

            break;

        case '-':

            rez = y - x;

            break;

        case '*':

            rez = y * x;

            break;

        case '/':

            rez = y / x;

            break;

    }

    push_nre(rez);

    semne[top_semne--] = 0;



}
int grad(char c)

{

    if(c == '+' || c == '-' || c == ')')

        return 1;

    if(c == '*' || c == '/')

        return 2;

    return 0;

}
void eliber(char forWho)

{

    int grad_actual = grad(forWho);



    while(top_semne != 0 && grad_actual <= grad(semne[top_semne]))

        calcul(semne[top_semne]);

}
void solve()

{

    for(int i = 0; i < l; ++i)

    {

        if(isDigit(a[i]))

            formnr(i);

        else if(a[i] == '(')

            push_semne(a[i]);

        else if(a[i] == ')')

        {

            if(top_semne != 0)

                eliber(')');

            semne[top_semne --] = 0;

        }

        else{

            if(top_semne != 0)

                eliber(a[i]);

            push_semne(a[i]);

        }



    }

    while(top_semne != 0)

        calcul(semne[top_semne]);

}





int main()

{

    f>>a;

    l = strlen(a);

    solve();

    g<<nre[top_nre];



    return 0;

}
