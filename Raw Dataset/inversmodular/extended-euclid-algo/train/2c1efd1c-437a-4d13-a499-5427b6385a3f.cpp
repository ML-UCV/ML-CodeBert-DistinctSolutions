#include <bits/stdc++.h>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int a,n;



void Read()

{

    f>>a>>n;

    f.close();

}



void gcd(long long &x,long long &y,int a,int b)

{

    if(!b)

    {

        x = 1;

        y = 0;

    }

    else

    {

        gcd(x, y, b,a % b);

        long long aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}



int main()

{

    long long inv = 0, ins;

    Read();

    gcd(inv, ins, a, n);



    while(inv <= 0)

        inv = n + inv % n;

    g<<inv;

    g.close();

    return 0;

}
