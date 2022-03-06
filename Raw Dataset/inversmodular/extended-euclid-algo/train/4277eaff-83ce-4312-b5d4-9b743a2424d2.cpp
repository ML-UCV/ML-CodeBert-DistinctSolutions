#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



typedef long long llu;



void euclid(llu a,llu b,llu &x,llu &y)

{

    if(!b)

    {

        x=1;

        y=0;

    }else{

        llu aux;

        euclid(b,a%b,x,y);

        aux=x;

        x=y;

        y=aux-(a/b)*y;

    }

}



int main()

{

    llu a,n,x,y;

    fin>>a>>n;

    euclid(a,n,x,y);

    if(x<=0)x=n+x%n;

    fout<<x;

    return 0;

}
