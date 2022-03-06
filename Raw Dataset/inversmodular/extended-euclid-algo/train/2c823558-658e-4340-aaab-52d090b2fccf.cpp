#include <fstream>


using namespace std;



ifstream cin("inversmodular.in");

ofstream cout("inversmodular.out");



typedef long long ll;



ll gcd(ll &x, ll &y, ll a, ll b)

{

    if(!b)

        x = 1, y = 0;

    else

    {

        gcd(x, y, b, a % b);

        ll aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}



int main()

{

    ll a, n, inv = 0, ins;



    cin >> a >> n;



    gcd(inv, ins, a, n);



    if(inv <= 0)

        inv = n + inv % n;



    cout << inv;



    return 0;

}
