#include <stdio.h>
#include <stdlib.h>


int n;

int A;



void fcc(long long &x, long long &y, int a, int b)

{

    if (!b)

        x = 1, y = 0;

    else

    {

        fcc(x, y, b, a % b);

        long long aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}



int main()

{

    long long sol = 0, s;



    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);



    scanf("%d %d", &A, &n);

    fcc(sol, s, A, n);



    if (sol <= 0)

        sol = n + sol % n;



    printf("%lld\n", sol);



    return 0;

}
