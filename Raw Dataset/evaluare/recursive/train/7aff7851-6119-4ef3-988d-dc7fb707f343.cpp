#include <bits/stdc++.h>




using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char C[100005];

int idx;



int expresie();



int factor()

{

    if (C[idx] == '(')

        return expresie();

    int ret = 0;

    while ('0' <= C[idx] && C[idx] <= '9')

        ret = ret * 10 + C[idx++] - '0';

    return ret;

}



int termen()

{

    int ret = factor();

    while (C[idx] == '*' || C[idx] == '/')

    {

        if (C[idx] == '*')

        {

            idx++;

            ret *= factor();

        }

        else

        {

            idx++;

            ret /= factor();

        }

    }

    return ret;

}



int expresie()

{

    idx++;

    int ret = termen();

    while (C[idx] != ')')

    {

        if (C[idx] == '+')

        {

            idx++;

            ret += termen();

        }

        else

        {

            idx++;

            ret -= termen();

        }

    }

    idx++;

    return ret;

}



int main()

{

    fin >> C + 1;

    C[0] = '(';

    C[strlen(C)] = ')';

    fout << expresie() << "\n";

    return 0;

}
