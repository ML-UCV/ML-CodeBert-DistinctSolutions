#include <fstream>
typedef long long ll;



using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void gcd(ll &x, ll &y, int a, int b)

{

    if(!b)

        x=1, y=0;

    else

    {

        gcd(x, y, b, a%b);

        ll aux=x;

        x=y;

        y=aux-y*(a/b);

    }

}



int main()

{

    int a, n;

    ll inv=0, y=0;

    fin >> a >> n;

    gcd(inv, y, a, n);

    if(inv<=0)

        inv=n+inv%n;

    fout << inv;

    return 0;

}
