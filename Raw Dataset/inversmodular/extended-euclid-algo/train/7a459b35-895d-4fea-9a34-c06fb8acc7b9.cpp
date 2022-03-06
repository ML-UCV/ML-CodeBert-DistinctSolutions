#include <stdio.h>






int A, N;



void gcd(long long &x, long long &y, int a, int b)

{

     if (!b)

         x = 1, y = 0;

     else

     {

         gcd(x, y, b, a % b);

         long long aux = x;

         x = y;

         y = aux - y * (a / b);

     }

}



int main()

{

    long long inv = 0, ins;



    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);



    scanf("%d %d", &A, &N);

    gcd(inv, ins, A, N);



    if (inv <= 0)

       inv = N + inv % N;



    printf("%lld\n", inv);



    return 0;

}
