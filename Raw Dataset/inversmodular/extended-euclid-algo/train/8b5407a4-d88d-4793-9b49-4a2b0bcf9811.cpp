#include <iostream>
#include <fstream>


using namespace std;



void euclid(long long &x, long long &y, long long a, long long b)

{

    if(b==0)

    {

        x=1;

        y=0;

    }

    else

    {

        euclid(x,y,b,a%b);

        int aux=x;

        x=y;

        y=aux -y*(a/b);



    }

}



int main()

{

    ifstream f("inversmodular.in");

    ofstream g("inversmodular.out");



    long long k=0,l=0,a,n;



    f>>a>>n;

    euclid(k,l,a,n);

    if(k<=0)

        k=n+k%n;

    g<<k;

    return 0;

}
