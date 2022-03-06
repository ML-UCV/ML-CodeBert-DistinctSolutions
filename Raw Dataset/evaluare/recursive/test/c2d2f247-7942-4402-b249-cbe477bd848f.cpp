#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



const int N = 100000;



char s[N+1];



int p;



int expresie();

int termen();

int factor();



int expresie()

{

    int sum = termen();

    while(s[p] == '+' || s[p] == '-')

    {

        if(s[p] == '+')

        {

            p++;

            sum += termen();

        }

        else

        {

            p++;

            sum -= termen();

        }

    }

    return sum;

}



int termen()

{

    int prod = factor();

    while(s[p] == '*' || s[p] == '/')

    {

        if(s[p] == '*')

        {

            p++;

            prod *= factor();

        }

        else

        {

            p++;

            prod /= factor();

        }

    }

    return prod;

}



int factor()

{

    int val = 0, semn = 1;

    while(s[p] == '-')

    {

        p++;

        semn = -semn;

    }

    if(s[p] == '(')

    {

        p++;

        val = expresie();

        p++;

        return semn * val;

    }

    while(isdigit(s[p]))

    {

        val = val * 10 + (s[p] - '0');

        p++;

    }

    return semn * val;

}



int main()

{

    fin.getline(s,100001);

    fout << expresie();

}
