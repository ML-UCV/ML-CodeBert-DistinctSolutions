#include<bits/stdc++.h>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long n,a,phi;

long long phi_euler(long long n)

{

    long long nn = n, ans = n;

    for(long long i = 2; i * i <= n; i ++)

    {

        if(nn % i == 0)

        {

            ans *= (i-1);

            ans /= i;

            while(nn % i == 0)

                nn /= i;

        }

    }

    if(nn != 1)

    {

        ans *= (nn-1);

        ans /= nn;

    }

    return ans;

}

long long lgput(long long base,long long exp)

{

    long long i;

    long long aux=base,ans=1;

    for(i=1; i<=exp; i*=2)

    {

        if(i&exp)

            ans=(1LL*ans*aux)%n;

        aux=(1LL*aux*aux)%n;

    }

    return ans;

}



int32_t main()

{

    fin>>a>>n;



    phi=phi_euler(n);



    fout<<lgput(a,phi-1);



    return 0;

}
