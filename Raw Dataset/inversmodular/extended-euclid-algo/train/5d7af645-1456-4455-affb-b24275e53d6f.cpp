#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void cmmdc(int a, int b, long long &x, long long &y)

{

    if(b == 0)

    {

        x = 1;

        y = 0;

    }

    else

    {

        long long x0,y0;

        cmmdc(b, a % b, x0, y0);

        x = y0;

        y = x0 - a / b * y0;

    }

}



int main()

{

    int a,n;

    long long x,y;

    fin >> a >> n;

    cmmdc(a,n,x,y);

    if(x <= 0)x = n + x % n;

    fout << x;

    return 0;

}
