#include <fstream>


using namespace std;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");



char s[100010];

int poz;

int eval();



int termen()

{

    int aux = 0;

    if(s[poz] == '(')

    {

        poz++;

        aux = eval();

        poz++;

        return aux;

    }

    while(s[poz] >= '0' && s[poz] <= '9')

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

        else aux /= termen();

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

        else aux -= produs();

    }



    return aux;

}



int main()

{

    cin >> s;

    cout << eval();

    return 0;

}
