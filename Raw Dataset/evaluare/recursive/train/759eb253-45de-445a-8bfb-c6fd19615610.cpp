#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char expresie[100002];

int p = 0;



long long functia1();

long long functia2();

long long functia3();



int main()

{

    fin >> expresie;

    fout << functia1();

    fin.close();

    fout.close();

    return 0;

}



long long functia1()

{

    long long r = functia2();

    while (expresie[p] == '+' || expresie[p] == '-')

    {

        if (expresie[p++] == '+')

        {

            r += functia2();

        }

        else

        {

            r -= functia2();

        }

    }

    return r;

}



long long functia2()

{

    long long r = functia3();

    while (expresie[p] == '*' || expresie[p] == '/')

    {

        if (expresie[p++] == '*')

        {

            r *= functia3();

        }

        else

        {

            r /= functia3();

        }

    }

    return r;

}



long long functia3()

{

    long long r = 0;

    if (expresie[p] == '(')

    {

        ++p;

        r = functia1();

        ++p;

    }

    else

    {

        while (expresie[p] >= '0' && expresie[p] <= '9')

        {

            r = r * 10 + expresie[p] - '0';

            ++p;

        }

    }

    return r;

}
