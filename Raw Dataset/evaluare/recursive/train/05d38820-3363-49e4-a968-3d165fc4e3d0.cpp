#include <bits/stdc++.h>




using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char s[100005];

int idx;



int Expresie();

int Termen();

int Factor();



int Expresie()

{

    idx++;

    int ret = Termen();

    while (s[idx] == '+' || s[idx] == '-')

        if (s[idx++] == '+')

            ret += Termen();

        else

            ret -= Termen();

    idx++;

    return ret;

}



int Termen()

{

    int ret = Factor();

    while (s[idx] == '*' || s[idx] == '/')

        if (s[idx++] == '*')

            ret *= Factor();

        else

            ret /= Factor();

    return ret;

}



int Factor()

{

    int ret = 0;

    if (s[idx] == '(')

         ret = Expresie();

    while ('0' <= s[idx] && s[idx] <= '9')

        ret = ret * 10 + s[idx++] - '0';

    return ret;

}



int main()

{

    fin >> (s + 1);

    s[0] = '(';

    s[strlen(s)] = ')';

    fout << Expresie();

    return 0;

}
