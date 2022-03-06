#include <bits/stdc++.h>


using namespace std;







ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int Quick(int a, int b, int mod)

{

    int p=1;

    while (b>0)

    {

        if (b%2==1) p=1ll*p*a%mod;

        b/=2;

        a=1ll*a*a%mod;

    }

    return p;

}

int Phi(int n)

{

    int sol,p;

    sol=n;

    for (p=2; n>1 and p*p<=n; p++)

    {

        if (n%p==0)

        {

            sol=sol/p*(p-1);

            while (n%p==0)

                n/=p;

        }

    }

    if (n>1) sol=sol/n*(n-1);

    return sol;

}





int main()

{

   int a,n;

    fin >> a >> n;

    fout << (Quick(a,(Phi(n)-1),n));
    return 0;

}
