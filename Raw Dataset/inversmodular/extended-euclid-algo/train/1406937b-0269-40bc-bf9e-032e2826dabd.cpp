#include <bits/stdc++.h>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int a,n,yy0,yy1,r,x,c,aux;



int main()

{

    f>>a>>n;

    yy0=0; yy1=1;

    aux=n;

    while (a!=0)

    {

        r=n%a;

        c=n/a;

        n=a;

        a=r;

        int y = yy0-c*yy1;

        yy0=yy1;

        yy1=y;

    }

    while (yy0<0) yy0+=aux;



    g<<yy0;



    return 0;

}
