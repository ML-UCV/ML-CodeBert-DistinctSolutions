#include <bits/stdc++.h>
using namespace std;



int a, b, x, y;



void euclid(int a, int b, int &x, int &y) {

    if(!b) {

        x = 1, y = 0;

        return;

    }

    int x1, y1;

    euclid(b, a % b, x1, y1);

    x = y1;

    y = x1 - y1 * (a / b);

}



int main() {

    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);



    scanf("%d%d", &a, &b);

    euclid(a, b, x, y);



    if(x < 0) { x += b; }

    printf("%d", x % b);

}
