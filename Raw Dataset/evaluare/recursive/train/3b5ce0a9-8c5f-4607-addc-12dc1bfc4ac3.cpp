#include <bits/stdc++.h>


using namespace std;



string v;

int i;

int numar();

int inm_imp();

int evaluare() {

    int nr = inm_imp();

    while (v[i] == '+' || v[i] == '-') {

        if (v[i++] == '+')

            nr += inm_imp();

        else

            nr -= inm_imp();

    }

    return nr;

}

int numar() {

    int nr = 0;

    if (v[i] == '(') {

        i++;

        nr = evaluare();

        i++;

    }

    else

        while(v[i] >= '0'&& v[i] <= '9') {

            nr = nr * 10 + (v[i] - '0');

            i++;

        }

    return nr;

}

int inm_imp() {

    int nr = numar();

    while (v[i] == '*' || v[i] == '/')

    {

        if (v[i++] == '*')

            nr *= numar();

        else

            nr /= numar();

    }

    return nr;

}

int main()

{

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");

    fin >> v;

    fout << evaluare();

    return 0;

}
