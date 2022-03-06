#include <bits/stdc++.h>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int a,n;



void euclid_e(long long &x, long long &y, int a, int b)

{

    if(!b) x=1,y=0;

    else {

        euclid_e(x,y,b,a%b);

        long long aux=x;

        x=y;

        y=aux-y*(a/b);

    }

}



int main()

{

    f>>a>>n;

    long long inv=0, ins;

    euclid_e(inv,ins,a,n);

    if(inv<=0) inv=n+inv%n;

    g<<inv<<'\n';

    f.close();

    g.close();

    return 0;

}
