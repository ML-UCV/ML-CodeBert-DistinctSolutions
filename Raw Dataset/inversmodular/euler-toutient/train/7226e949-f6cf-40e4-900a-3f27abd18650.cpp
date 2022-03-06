#include <bits/stdc++.h>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long y,n;

void phi(long long a)

{

    long long p=a,s=a,x;

    for(long long i=2;i*i<=a;++i)

    {

        if(a%i==0)

        {

            while(a%i==0)a/=i;

            p=p/i*(i-1);

        }

    }

    if(a>1)p=p/a*(a-1);

    x=p-1;

    p=y;

    y=1;

    while(x)

    {

        if(x%2)y*=p,y%=s;

        p=(p*p)%s;

        x/=2;

    }

}

int main()

{

    fin>>y>>n;

    phi(n);

    fout <<y%n << '\n';

    return 0;

}
