#include <iostream>
#include <fstream>


using namespace std;



typedef long long ll;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



ll a, b, d, yy, xx;



ll gcd(ll a, ll b, ll &x, ll &y)

{

    if(!b)

    {

        x=1, y=0;

        return a;

    }

    ll rez, y1, x1;

    rez=gcd(b, a%b, x1, y1);

    x=y1;

    y=x1-(a/b)*y1;

    return rez;

}



int main()

{

    in>>a>>b;

    d=gcd(a, b, xx, yy);

    if(xx<=0) xx=b+xx%b;

    out<<xx;

    return 0;

}
