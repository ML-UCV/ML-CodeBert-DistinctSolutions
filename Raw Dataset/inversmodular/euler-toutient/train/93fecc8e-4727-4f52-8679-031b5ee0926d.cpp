#include <bits/stdc++.h>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void invers_mod(long long a,long long b,long long &x,long long &y)

{

    if(b==0)

    {

        x=1,y=0;

    }

    else

    {

        invers_mod(b,a%b,x,y);

        int aux=x;

        x=y;

        y=aux-(a/b)*y;

    }

}





int main()

{

    long long n,m,x,y;

    fin>>n>>m;

    invers_mod(n,m,x,y);

    if(x<=0)

        x=m+x;

    fout<<x;

    return 0;

}
