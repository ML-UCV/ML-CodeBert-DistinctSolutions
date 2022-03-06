#include <bits/stdc++.h>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



long long ext_euclid(long long a, long long b, long long &x, long long &y)

{

    if(b == 0) {

        x = 1;

        y = 0;

        return a;

    }

    long long x0, y0;

    long long d = ext_euclid(b, a % b, x0, y0);

    x = y0;

    y = x0 - y0 * (a / b);

    return d;

}



int main()

{

    long long a, b, x, y;



    fin >> a >> b;

    ext_euclid(a, b, x, y);

    x = (x + b) % b;

    fout << x << "\n";

    return 0;

}
