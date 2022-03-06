#include <fstream>
#include <cstring>
using namespace std;

ifstream cin("evaluare.in");

ofstream cout("evaluare.out");

const int N = 300001;

char c[N];

int stiva [100001], vf;

int prio(char x)

{

    if(x == '(' or x == ')')

        return 0;

    if(x == '+' or x == '-')

        return 1;

    return 2;

}

int operatie( int x, int y , char semn)

{

    switch(semn)

    {

        case '+': return x + y;

        case '-': return x - y;

        case '*': return x * y;

        case '/': return x / y;

    }

}

int eval(char []);

void postfix(char[]);

int main()

{

    cin >> c;

    postfix(c);

    cout << eval(c);

    return 0;

}

void postfix(char x[])

{

    int poz = 0;

    int n = strlen(x);

    char aux[N]= {0};

    for( int i =0 ;i < n ;i ++)

    {

        if(x[i] >='0' and x[i]<='9')

            aux[poz++]=x[i];

        else

        {

            if(i > 0 and x[i-1]>='0' and x[i -1]<='9')

                aux[poz++]= ' ';

            if(x[i] == '(')

                stiva[vf++]= x[i];

            else

                if(x[i] == ')')

            {

                while(stiva[vf - 1] !='(')

                    aux[poz++] = stiva[--vf];

                vf--;

            }

            else

            {

                while(vf != 0 and prio(x[i]) <= prio(stiva[vf- 1]))

                    aux[poz ++]= stiva[--vf];

                stiva[vf++] = x[i];

            }



        }

    }

    if(aux[poz - 1] >='0' and aux[poz - 1] <='9')

        aux[poz++] = ' ';

    while(vf != 0)

    {



        aux[poz++] = stiva[--vf];

    }

    strcpy(x, aux);

}

int eval(char x[])

{

    int n = strlen(x);

    int numar = 0;

    for( int i =0 ; i < n ;i++)

        if(x[i] >='0' and x[i]<='9')

            numar = numar * 10 +x[i] -'0';

        else

            if(x[i] == ' ')

        {

            stiva[vf++] = numar;

            numar = 0;

        }

        else

        {

            int nr2 = stiva[--vf], nr1= stiva[--vf];

            stiva[vf++] = operatie(nr1,nr2, x[i]);

        }

    return stiva[vf - 1];

}
