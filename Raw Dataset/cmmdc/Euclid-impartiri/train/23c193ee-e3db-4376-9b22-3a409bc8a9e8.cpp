#include <bits/stdc++.h>
using namespace std;

int d,i,r;

int main()

{

    ifstream f("cmmdc.in");

    ofstream g("cmmdc.out");

    f>>d>>i;

    while(i)

    {

        r=d%i;

        d=i;

        i=r;

    }

    if(d==1)

        g<<"0";

    else

        g<<d;

    return 0;

}
