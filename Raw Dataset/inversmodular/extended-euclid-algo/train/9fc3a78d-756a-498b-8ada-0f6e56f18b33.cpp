#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

void gcd(long long &x,long long &y,int a,int b)

{

    if(b==0)

    {

        x = 1;

        y = 0;

    }

    else

    {

        gcd(x,y,b,a%b);

        int aux = x;

        x = y;

        y = aux - (a/b)*y;

    }

}

int main()

{

    long long x,y;

    int a,n;

    fin>>a>>n;

    gcd(x,y,a,n);

    if(x<=0)

        x = n + x%n;

    fout<<x;

    return 0;

}
