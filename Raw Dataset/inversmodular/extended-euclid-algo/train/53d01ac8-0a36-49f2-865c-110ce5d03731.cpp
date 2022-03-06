#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

void gcd_extended(int a, int b, int &d, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;

    } else {
        int x0, y0;
        gcd_extended(b, a % b, d, x0, y0);
        x = y0;
        y = x0 - (a / b) * y0;
    }
}

int main() {
    freopen("inversmodular.in", "r", stdin);
    freopen("inversmodular.out", "w", stdout);

    int A, N;
    scanf("%d %d", &A, &N);

    int d, x, y;
    gcd_extended(A, N, d, x, y);
    while (x <= 0) {
        x += N;
        x %= N;
    }
    printf("%d\n", x);

    return 0;
}
