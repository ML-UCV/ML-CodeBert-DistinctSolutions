#include <bits/stdc++.h>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



void usain_bolt()

{

    ios::sync_with_stdio(false);

    fin.tie(0);

}



long long ext_gcd(long long a, long long b, long long & x, long long & y)

{

    if(b == 0) {

        x = 1;

        y = 0;

        return a;

    }

    long long x1, y1;

    long long d = ext_gcd(b, a % b, x1, y1);

    y = x1 - (a / b) * y1;

    x = y1;

    return d;

}



int main()

{

    usain_bolt();



    long long a, n;



    fin >> a >> n;



    long long x, y;

    ext_gcd(a, n, x, y);

    x = (x + n) % n;

    fout << x;

    return 0;

}
