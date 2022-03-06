#include <bits/stdc++.h>




using namespace std;





void gcdExtended(int a, int b, long long *x, long long *y) {



    if (a == 0) {

        *x = 0;

        *y = 1;

        return;

    }



    long long x1, y1;

    gcdExtended(b%a, a, &x1, &y1);





    *x = y1 - (b/a) * x1;

    *y = x1;

}



int main()

{

    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);



    long long x, y;

    int a, b, c = 1;



    scanf("%d %d", &a, &b);
    gcdExtended(a, b, &x, &y);







    if (x <= 0)

        x = b + x % b;

    printf("%d\n", x);



    return 0;

}
