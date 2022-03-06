#include <fstream>
using namespace std;

ifstream cin ("inversmodular.in");

ofstream cout("inversmodular.out");

int a, b, c, d, x, y;

void gcd(int a, int b, int &x, int &y) {

    if (!b) {

        x = 1;

        y = 0;

    }

    else {

        int x0, y0;

        gcd(b, a % b, x0, y0);

        x = y0;

        y = x0 - (a / b) * y0;

    }

}

int main() {

    int a, n;

    cin >> a >> n;

    int inv, ins;

    gcd(a, n, inv, ins);

    if (inv <= 0) inv = n + inv % n;

    cout << inv;

    return 0;

}
