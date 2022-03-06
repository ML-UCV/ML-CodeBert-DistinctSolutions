#include <bits/stdc++.h>
using namespace std;

int n, p;

char s[100005];

int adunare_scadere(int & p);

int inmultire_impartire(int & p);

int paranteze(int & p);

int valoare(int & p);

int adunare_scadere(int & p)

{

    int rez = inmultire_impartire(p);

    while(p < n && (s[p] == '+' || s[p] == '-'))

    {

        p ++;

        if(s[p - 1] == '+')rez = rez + inmultire_impartire(p);

        else rez = rez - inmultire_impartire(p);

    }

    return rez;

}

int inmultire_impartire(int & p)

{

    int rez = paranteze(p);

    while(p < n && (s[p] == '*' || s[p] == '/'))

    {

        p ++;

        if(s[p - 1] == '*')rez = rez * paranteze(p);

        else rez = rez / paranteze(p);

    }

    return rez;

}

int paranteze(int & p)

{

    int rez = 0;

    if(s[p] == '(')

    {

        p ++;

        rez = adunare_scadere(p);

        p ++;

    }

    else rez = valoare(p);

    return rez;

}

int valoare(int & p)

{

    int semn, rez = 0;

    if(s[p] == '-')semn = -1, p ++;

    else semn = 1;

    while(s[p] >= '0' && s[p] <= '9' && p < n)

    {

        rez = rez * 10 + (s[p] - '0');

        p ++;

    }

    return semn * rez;

}

int main()

{

    ifstream f("evaluare.in");

    ofstream g("evaluare.out");

    f.getline(s, sizeof(s));

    n = strlen(s);

    g << adunare_scadere(p);

    return 0;

}
