#include<bits/stdc++.h>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");





int n,a,phi;



int phi_euler(int nr)

{

    int i,phii=nr;

    for(i=2; i*i<=nr; i++)

    {

        if(nr%i==0)

        {

            phii/=i;

            phii*=(i-1);

            while(nr%i==0)

                nr=nr/i;

        }

    }

    if(nr!=1)

    {

        phii/=nr;

        phii*=(nr-1);

    }

    return phii;

}



int lgput(int base,int exp)

{

    long long i;

    int aux=base,ans=1;

    for(i=1; i<=exp; i*=2)

    {

        if(i&exp)

            ans=(1LL*ans*aux)%n;

        aux=(1LL*aux*aux)%n;

    }

    return ans;

}



int main()

{

    fin>>a>>n;

    phi=phi_euler(n);

    fout<<lgput(a,phi-1);

    return 0;

}
