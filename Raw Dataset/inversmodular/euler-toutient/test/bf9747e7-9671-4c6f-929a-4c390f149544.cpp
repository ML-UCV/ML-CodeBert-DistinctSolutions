#include <bits/stdc++.h>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

typedef long long ll;

ll a,n;

ll phi(ll nr)

{

    ll ans=nr;

    for(int d=2;d*d<=nr;d++)

    {

        if(nr%d==0)

        {

            while(nr%d==0)

                nr/=d;

            ans-=ans/d;

        }

    }

    if(nr>1)ans-=ans/nr;

    return ans-1;

}

ll exp(ll a, ll p)

{

    ll rez=1;

    while(p)

    {

        if(p%2==0)

        {

            a=(a*a)%n;

            p/=2;

        }

        else

        {

            rez=(rez*a)%n;

            p--;

        }

    }

    return rez;

}

int main()

{

    fin>>a>>n;

    fout<<exp(a,phi(n));

    return 0;

}
