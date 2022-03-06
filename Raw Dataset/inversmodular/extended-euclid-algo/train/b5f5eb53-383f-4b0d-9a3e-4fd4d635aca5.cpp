#include <bits/stdc++.h>
using namespace std;





ifstream in("inversmodular.in");

ofstream out("inversmodular.out");

void eclext(int a, int b, int *d, int *x, int *y) {

    if (b == 0) {

        *d = a;

        *x = 1;

        *y = 0;

    } else {

        int x0, y0;

        eclext(b, a % b, d, &x0, &y0);

        *x = y0;

        *y = x0 - (a / b) * y0;

    }

}

int main() {

    int a, n, d, x, y;

    in >> a >> n;

    eclext(a, n, &d, &x, &y);

    if(x > 0)

        out << x;

    else

        out << n + x % n;

    return 0;

}
