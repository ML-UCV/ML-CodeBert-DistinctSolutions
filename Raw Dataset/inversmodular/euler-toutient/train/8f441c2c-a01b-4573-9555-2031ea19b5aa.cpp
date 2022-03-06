#include <bits/stdc++.h>


using namespace std;

ifstream fin ("inversmodular.in");

ofstream fout("inversmodular.out");

int Phi(int n)

{

    int sol,p;

    sol = n;

    p = 2;

    for( p = 2; n > 1 && p * p <= n; p++)

    {

        if(n % p == 0)

        {

            sol = sol / p *(p-1);

            while(n%p == 0)

                n/=p;

        }

    }

    if(n > 1)

        sol = sol / n *(n-1);

    return sol;

}



int exp(int a, int n,int mod)

{

    int sol=1;

    while(n>0)

    {

        if(n % 2 == 1)

            sol = 1LL*sol*a%mod;

        n/=2;

        a=1LL*a*a%mod;



    }

    return sol;



}



int main()

{

    int a , n;

    fin >> a >> n;

    int b;

    b=exp(a,Phi(n)-1,n);

    fout<<b;

    fin.close();

    fout.close();

    return 0;

}
