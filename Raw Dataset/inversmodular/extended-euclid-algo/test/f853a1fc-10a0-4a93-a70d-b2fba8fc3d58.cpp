#include <bits/stdc++.h>




using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



inline void gcd(long long a, long long b, long long &x, long long &y)

{

     if (!b)

        x = 1, y = 0;

     else

     {

         long long x0, y0;

         gcd(b, a % b, x0, y0);

         x = y0;

         y = x0 - (a / b) * y0;

     }

}



int main()

{

    long long a, n, inv, y;

    in >> a >> n;

    gcd(a, n, inv, y);

    if (inv < 0)

        inv = n + inv % n;

    out << inv;

    return 0;

}
