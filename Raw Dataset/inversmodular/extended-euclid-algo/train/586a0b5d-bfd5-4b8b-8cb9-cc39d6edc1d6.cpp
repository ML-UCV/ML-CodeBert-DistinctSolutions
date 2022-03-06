#include <fstream>
using namespace std;
void euclid(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
    } else {
        int x0, y0;
        euclid(b, a % b, &x0, &y0);
        *x = y0;
        *y = x0 - (a / b) * y0;
    }
}
ifstream fin( "inversmodular.in" );
ofstream fout( "inversmodular.out" );
int main() {
    int a, n, x, y;
    fin >> a >> n;
    euclid( a, n, &x, &y );
    if ( x <= 0 )
        x = n + x % n;
    fout << x;

    return 0;
}
