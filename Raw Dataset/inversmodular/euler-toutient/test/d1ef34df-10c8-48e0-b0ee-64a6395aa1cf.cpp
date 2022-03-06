#include <bits/stdc++.h>


using namespace std;



long long invMod(long long &x, long long &y, int a, int b)

{

    if (!b)

        x = 1, y = 0;

    else

    {

        invMod(x, y, b, a%b);

        long long aux = x;

        x = y;

        y = aux - y*(a/b);

    }

}

long long x, y;

int a, b;

int main()

{

    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);

    cin>>a>>b;

    invMod(x,y,a,b);

    if (x < 0) x = b + x;

    cout<<x<<'\n';

    return 0;

}
