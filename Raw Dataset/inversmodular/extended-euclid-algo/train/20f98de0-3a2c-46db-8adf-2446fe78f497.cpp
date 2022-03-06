#include <bits/stdc++.h>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

typedef long long ll;

ll eucl(ll A,ll B, ll &X, ll &Y)

{

    if(B==0)

    {

        X=1;

        Y=0;

        return A;

    }

    ll X0,Y0,D;

    D=eucl(B,A%B,X0,Y0);

    X=Y0;

    Y=X0-(A/B)*Y0;

    return D;

}

int main()

{

    ll x,y,A,N;

    ll inv;

    fin>>A>>N;

    inv=eucl(A,N,x,y);

    while(x<1) x+=N;

    while(x>N-1) x-=N;

    fout<<x<<"\n";

    return 0;

}
