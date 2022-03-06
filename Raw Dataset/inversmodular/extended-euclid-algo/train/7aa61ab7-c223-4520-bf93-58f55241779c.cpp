#include <iostream>
#include <fstream>


using namespace std;



void gcd(long long &x, long long &y, long long a, long long b)

{

    if(b==0)

    {

        x=1;

        y=0;

    }

    else

    {

        gcd(x,y,b,a%b);

        int aux=x;

        x=y;

        y=aux -y*(a/b);



    }

}



int main()

{

    ifstream f("inversmodular.in");

    ofstream g("inversmodular.out");



    long long inv=0,ins=0,a,n;



    f>>a>>n;

    gcd(inv,ins,a,n);

    if(inv<=0)

        inv=n+inv%n;

    g<<inv;

    return 0;

}
