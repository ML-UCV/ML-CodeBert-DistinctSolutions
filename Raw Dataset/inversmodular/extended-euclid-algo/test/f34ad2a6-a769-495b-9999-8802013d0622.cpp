#include <bits/stdc++.h>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long x1,w;

int p,n;

void cmmdc(int a,int b,long long &x,long long &y)

{

    if(b==0)

    {

        x=1;

        y=0;

    }



    else

    {

        long long x0;

        long long y0;

        cmmdc(b,a%b,x0,y0);

        x=y0;

        y=x0-(a/b)*y0;

    }

}

int main()

{

    fin>>p>>n;

    cmmdc(p,n,x1,w);

    if(x1<=0)x1=n+x1%n;

    fout <<x1 << '\n';

    return 0;

}
