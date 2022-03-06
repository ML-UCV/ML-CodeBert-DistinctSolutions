#include <bits/stdc++.h>


using namespace std;



int A, N;



void modularinverse(long long &x, long long &y, int a, int b)

{

    if (b == 0)

    {

        x = 1;

        y = 0;

        return;

    }

    modularinverse(x, y, b, a % b);

    long long aux = x;

    x = y;

    y = aux - y * (a / b);

}

int main()

{

    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);

    scanf("%d%d", &A, &N);

    long long x = 0, y;

    modularinverse(x, y, A, N);

    if (x <= 0)

        x = N + x % N;

    printf("%lld", x);

    return 0;

}
