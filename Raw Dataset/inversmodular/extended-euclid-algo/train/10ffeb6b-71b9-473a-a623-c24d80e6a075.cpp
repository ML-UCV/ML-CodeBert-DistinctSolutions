#include <bits/stdc++.h>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long inv = 0,ins,a,n;

void inv_m(long long &x,long long &y, long long a, long long b)

{

    if(!b)

    {

        x = 1;

        y = 0;

    }

    else

    {

        inv_m(x,y,b,a%b);

        long long aux = x;

        x = y;

        y = aux-y*(a/b);

    }

}

int main()

{

    fin >> a >> n;

    inv_m(inv,ins,a,n);

    if(inv <= 0)

        inv = n+inv%n;

    fout << inv;

    return 0;

}
