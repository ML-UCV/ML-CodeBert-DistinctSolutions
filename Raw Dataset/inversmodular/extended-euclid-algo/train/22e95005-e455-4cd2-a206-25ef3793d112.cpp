#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <cmath>
using namespace std;



void gcd(int &x, int &y, int a, int b) {

    if(b == 0) x = 1, y = 0;

    else{

        gcd(x, y, b, a % b);

        int aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}



int main() {

    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);

    int inv, ins, A, N;

    scanf("%d%d", &A, &N);

    inv = 0;

    gcd(inv, ins, A, N);

    if(inv <= 0) inv = N + inv % N;

    printf("%d\n", inv);

    return 0;

}
