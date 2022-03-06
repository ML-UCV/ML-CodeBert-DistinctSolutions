#include <bits/stdc++.h>


using namespace std;

ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");







char expresie[100005];

int n;

int poz;



int eval();

int factor();

int find_nr();

bool cifra(char c);

int rez(int p1 , char oper , int p2);





int main()

{

    while (!fin.eof())

    {

        fin >> expresie[n];

        n++;

    }

    n--;

    fout << eval();



    return 0;

}



int eval()

{

    int nr1 = 0, nr2;

    char oper;

    while (poz < n && expresie[poz] != ')')

    {

        nr1 += factor();

        if (poz >= n || expresie[poz] == ')')

            return nr1;



        oper = expresie[poz];



        poz++;

        nr2 = factor();

        nr1 = rez(nr1 , oper , nr2);

    }

    return nr1;

}



int factor()

{

    int nr1 = 0 , nr2;

    char oper;

    while (poz < n && expresie[poz] != ')')

    {

        nr1 += find_nr();

        if (poz >= n || expresie[poz] == ')')

            return nr1;



        oper = expresie[poz];

        if (oper == '-' || oper == '+')

            return nr1;



        poz++;

        nr2 = find_nr();

        nr1 = rez(nr1 , oper , nr2);

    }

    return nr1;

}



int find_nr()

{

    int nr = 0;

    if (cifra(expresie[poz]) == true)

    {

        while (cifra(expresie[poz]))

        {

            nr = nr * 10 + int(expresie[poz]) - 48;

            poz++;

        }

    }

    else if (expresie[poz] == '(')

    {

        poz++;

        nr = eval();

        poz++;

    }

    return nr;

}



bool cifra(char c)

{

    if (c >= '0' && c <= '9')

        return true;

    return false;

}



int rez(int p1 , char oper , int p2)

{

    if (oper == '-')

        return p1 - p2;

    if (oper == '+')

        return p1 + p2;

    if (oper == '/')

        return p1 / p2;

    if (oper == '*')

        return p1 * p2;

}
