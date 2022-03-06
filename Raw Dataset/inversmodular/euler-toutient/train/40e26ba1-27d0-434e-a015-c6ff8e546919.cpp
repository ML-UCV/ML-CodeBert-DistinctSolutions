#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

ifstream in ("inversmodular.in");

ofstream out("inversmodular.out");

long long a, n, i, diviz;

long long explog(long long x1, long long n1)

{

    long long p=1;

    long long x=x1;

    while(n1>0)

    {

        if(n1&1)

        {

            p=(p*x)%n;



            n1--;

        }

        x=(x*x)%n;

        n1>>=1;

    }

    return p;

}

long long ptphi(long long x)

{

    long long temp=x;

    for(i=2; i*i<=x; i++)

    {

        if(x%i==0)

        {

            while(x%i==0) {x/=i;}

            temp=temp/i*(i-1);

        }

    }

    if(x>1) temp=temp/x*(x-1);

    return temp;

}

int main()

{

    in>>a>>n;

    out<<explog(a, ptphi(n)-1);

    return 0;

}
