#include <bits/stdc++.h>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

typedef long long ll;

ll A,N;



void Euler(ll a,ll b,ll &x,ll &y)

{

    if( !b )

    {

        x=1;

        y=0;

        return;

    }

    ll x0,y0;

    Euler(b,a%b,x0,y0);

    x=y0;

    y=x0-(a/b)*y0;

}



int main()

{

    f>>A>>N;





    ll x,y;

    Euler(A,N,x,y);

    x%=N;

    if(x<0) x=N+x;





    g<<x;



    return 0;

}
