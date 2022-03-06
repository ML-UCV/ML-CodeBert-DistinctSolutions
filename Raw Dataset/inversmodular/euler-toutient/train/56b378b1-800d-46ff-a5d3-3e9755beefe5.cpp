#include<fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

unsigned long long a,n,MOD;

unsigned long long lgnp(unsigned long long n, unsigned long long p)

{

    n=n%MOD;

    unsigned long long r=1;

    while(p)

    {

        if(p%2==1) r=(1LL*r*n)%MOD;

        n=(n*n*1LL)%MOD;

        p/=2;

    }

    return r%MOD;

}

unsigned long long phi(unsigned long long n)

{

    unsigned long long d=2,fm,nr=1;

    do

    {

        fm=0;

        while(n%d==0)

        {

            n/=d;

            fm++;

        }

        if(fm>0) nr*=(d-1)*lgnp(d,fm-1);

        d++;

        if(d*d>n&&n>1)

        {

            nr=nr*(n-1);

            n=1;

        }

    }

    while(n>1);

    return nr;

}

int main()

{

    fin>>a>>n;

    MOD=n;

    fout<<lgnp(a,phi(n)-1);



    return 0;

}
