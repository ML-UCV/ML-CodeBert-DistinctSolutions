#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");
int Phi(int n)

{

    int p,sol;

    sol=n;

    for(p=2;n>1 && p*p<=n;p++)

    {

        if(n%p==0)

        {

            sol=sol/p*(p-1);

            while(n%p==0)

                n/=p;

        }

    }

    if(n>1) sol=sol/n*(n-1);

    return sol;

}



int LogP(int a,int n,int MOD)

{

    int p=1;

    while(n>0)

    {

        if(n%2==1) p=1LL*p*a%MOD;

        n/=2;

        a=1LL*a*a%MOD;

    }

    return p;

}



int main()

{

    int a,n;

    fin>>a>>n;

    fout<<LogP(a,Phi(n)-1,n);

    return 0;

}
