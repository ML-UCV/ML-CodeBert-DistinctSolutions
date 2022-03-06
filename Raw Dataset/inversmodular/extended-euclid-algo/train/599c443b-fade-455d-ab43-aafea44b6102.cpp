#include <stdio.h>


using namespace std;

typedef long long ll;



int A, N;



void gcd(ll &x, ll &y, int a, int b)

{

     if (!b)

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

    ll inv = 0, ins;



    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);



    scanf("%d %d", &A, &N);

    gcd(inv, ins, A, N);



    if (inv <= 0)

       inv = N + inv % N;



    printf("%lld\n", inv);



    return 0;

}
