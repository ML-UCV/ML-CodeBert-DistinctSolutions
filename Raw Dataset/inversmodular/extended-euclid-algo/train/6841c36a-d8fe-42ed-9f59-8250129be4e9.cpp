#include <bits/stdc++.h>
using namespace std;



void euclid(int a, int b, long long &x, long long &y){

    if(b == 0){

        x = 1; y = 0;

        return ;

    }



    long long x0, y0;

    euclid(b, a % b, x0, y0);

    x = y0;

    y = x0 - 1LL * (a / b) * y0;

}



int main()

{

    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);



    int a, MOD;

    scanf("%d%d", &a, &MOD);



    long long inv_mod, aux;

    euclid(a, MOD, inv_mod, aux);



    inv_mod = (inv_mod % MOD + MOD) % MOD;

    printf("%d", inv_mod);



    return 0;

}
