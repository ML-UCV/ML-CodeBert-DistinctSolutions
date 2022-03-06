#include <bits/stdc++.h>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



long long a,b;



void euclid_extins(long long a,long long b,long long &x,long long &y)

{

    if(b==0)

        x=1,y=0;

    else

    {

        euclid_extins(b,a%b,x,y);

        long long aux=y;

        y=x-(a/b)*y;

        x=aux;

    }

}



int main()

{

    long long m,n,x,y;

    fin>>n>>m;

    euclid_extins(n,m,x,y);

    if(x<=0)

        x=m+x%m;

    fout<<x;

    return 0;

}
