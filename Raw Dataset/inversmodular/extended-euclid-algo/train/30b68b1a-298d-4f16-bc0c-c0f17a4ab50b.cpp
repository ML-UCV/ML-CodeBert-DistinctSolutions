#include <fstream>


std::ifstream fin("inversmodular.in");

std::ofstream fout("inversmodular.out");



typedef long long ll;



ll gcd(ll a, ll b, ll &x, ll &y)

{

    if(b == 0)

    {

        x = 1;

        y = 0;

        return a;

    }

    else

    {

        ll x0,y0,d;

        d = gcd(b,a%b,x0,y0);

        x = y0;

        y = x0 - (a/b)*y0;

    }

}



int main()

{

    ll a, n;

    ll inv = 0, ins;

    fin >> a >> n;

    gcd(a,n,inv,ins);



    if(inv < 0)

    {

        inv = n + inv % n;

    }



    fout << inv;

}
