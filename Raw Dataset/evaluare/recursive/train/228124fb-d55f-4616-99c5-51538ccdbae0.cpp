#include <fstream>
using namespace std;

ifstream cin("evaluare.in");



ofstream cout("evaluare.out");



char s[100005];



int poz;



int eval();



int produs();

int termen()

{

    int aux = 0 ;

    if(s[poz] == '(')

    {

        poz++;

        aux = eval();

        poz++;

        return aux;

    }

    while('0' <= s[poz] && s[poz] <= '9')

        aux = aux * 10 + (s[poz++] - '0');

    return aux;

}

int produs()

{

    int aux = termen();

    while(s[poz] == '*' || s[poz] == '/')

    {

        if(s[poz++] == '*')

            aux = aux * termen();

        else aux = aux / termen();

    }

    return aux;

}

int eval()

{

    int aux = produs();

    while(s[poz] == '+' || s[poz] == '-')

    {

        if(s[poz++] == '+')

            aux = aux + produs();

        else aux = aux - produs();

    }

    return aux;

}

int main()

{

    cin >> s;

    cout << eval();

    return 0;

}
