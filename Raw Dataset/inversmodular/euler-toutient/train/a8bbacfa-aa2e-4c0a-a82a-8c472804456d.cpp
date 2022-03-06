#include <bits/stdc++.h>
using namespace std;

ifstream fin ("inversmodular.in");

ofstream fout("inversmodular.out");

long long phi,n;



void descomp(long long n)

{

    for(long long i=2;i*i<=n;i++)

    if(n%i==0)

    {

        while(n%i==0)

            n/=i;

        phi/=i;

        phi*=(i-1);

    }

    if(n!=1)

        phi/=n,phi*=(n-1);

}





long long ridica (long long baza,long long exp)

{

    long long sol=1;

    while (exp!=0)

    {

        if (exp%2==1)

            {

                sol=sol*baza;

                sol%=n;

            }

        baza=baza*baza;

        baza%=n;

        exp/=2;

    }

    return sol;

}



int main()

{

    long long a;

    fin>>a>>n;

    phi=n;

    descomp (n);

    fout<<ridica(a,phi-1);

    return 0;

}
