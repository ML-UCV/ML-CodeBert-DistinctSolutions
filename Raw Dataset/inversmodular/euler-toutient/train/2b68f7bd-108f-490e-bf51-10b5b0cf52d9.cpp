#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int n, a;

long long x;



int prim(int n)

{

    if(n<2)

        return 0;

    if(n%2==0 && n>2)

        return 0;

    for(int d=3;d*d<=n;d+=2)

        if(n%d==0)

            return 0;

    return 1;

}



long long P(int a, int n, int mod)

{

    long long p=1;

    while(n)

    {

        if(n%2==1)

            p=((p%mod)*(a%mod))%mod;

        a=(1LL*(a%mod)*(a%mod))%mod;

        n/=2;

    }

    return p;

}



int Phi(int n)

{

    int r=n, d=2;

    while(n>1)

    {

        if(n%d==0)

        {

            r=r/d*(d-1);

            while(n%d==0)

                n/=d;

        }

        d++;

        if(d*d>n)

            d=n;

    }

    return r;

}



int main()

{

    fin >> a >> n;

    x = P(a,Phi(n)-1,n);

    fout << x;

    return 0;

}
