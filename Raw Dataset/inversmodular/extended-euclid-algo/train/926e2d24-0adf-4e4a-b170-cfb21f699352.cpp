#include <fstream>
using namespace std;

void euclid_e ( int a, int b, int &x, int &y, int &d ) {

    if ( b == 0 ) {

        d = a, x = 1, y = 0;

        return;

    }

    int x1, y1, q = a / b;

    euclid_e ( b, a % b, x1, y1, d );

    x = y1, y = x1 - y1 * q;

}

int main()

{

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    int a, n, x, y, d;

    fin >> a >> n;

    euclid_e( a, n, x, y, d );

    x %= n;

    if( x < 0 )

        x+= n;

    fout << x;

    fin.close();

    fout.close();

    return 0;

}
