#include <bits/stdc++.h>
#include <fstream>
using namespace std;







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
int Phi(int n)

{

    int sol=n,p;

    for(p=2;p*p<=n and n>1;p++)

    {

        if(n%p==0)

            sol=sol/p*(p-1);

        while(n%p==0)

            n/=p;

    }

    if(n>1)

        sol=sol/n*(n-1);

    return sol;

}



int main()

{

    int a,phi,n;

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    fin>>a>>n;

    phi=Phi(n);

    fout<<LogP(a,phi-1,n)<<"\n";

    fin.close();

    fout.close();





    return 0;

}
