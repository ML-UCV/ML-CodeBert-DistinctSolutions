#include <fstream>


using namespace std;

void euclid_e(int a, int b, int &x, int &y, int &d){

  if ( b == 0 ){

    d = a;

    x = 1;

    y = 0;

    return;

  }

  int xx, yy, q = a/b;

  euclid_e(b, a%b, xx, yy, d);

  x = yy;

  y = xx - yy*q;

}

int main()

{

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    int a, n, x, y, d, div, exp, nrd, r;

    fin >> a >> n;

    euclid_e(a, n, x, y, d);

    x %= n;

    if ( x < 0 ){

      x += n;

    }

    fout << x;

    return 0;

}
