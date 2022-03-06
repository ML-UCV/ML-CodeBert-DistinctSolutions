#include <iostream>
#include <fstream>


using namespace std;



ifstream x("inversmodular.in");

ofstream y("inversmodular.out");



int a,n,yy,sol;



void e_e(int &xx, int &yy, int a, int b)

{

    if(!b)

        xx=1,yy=0;

    else

    {

        e_e(xx,yy,b,a%b);

        int aux=xx;

        xx=yy;

        yy=aux-yy*(a/b);

    }

}



int main()

{

    x>>a>>n;

    e_e(sol,yy,a,n);

    if(sol<=0)

        sol=n+sol%n;

    y<<sol;

    x.close();

    y.close();

    return 0;

}
