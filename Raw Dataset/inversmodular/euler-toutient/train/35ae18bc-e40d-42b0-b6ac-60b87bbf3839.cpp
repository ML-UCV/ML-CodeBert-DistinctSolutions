#include <bits/stdc++.h>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int LogP(int a, int n, int mod)

{

    int p=1;

    while (n)

    {

        if (n%2==1)

            p=1ll*p*a%mod;

        a=1ll*a*a%mod;

        n/=2;

    }

    return p;

}

int phi(int n)

{

    int sol=n,p;

    for (p=2; n>1 and p*p<=n; p++)

    {

        if (n%p==0)

        sol=sol/p*(p-1);

        while (n%p==0)

        n/=p;



    }

    if (n>1)

    sol=sol/n*(n-1);

    return sol;

}

int main()

{

    int a,n;

    fin >> a >> n;

    fout << (LogP(a,(phi(n)-1),n));
    return 0;

}
