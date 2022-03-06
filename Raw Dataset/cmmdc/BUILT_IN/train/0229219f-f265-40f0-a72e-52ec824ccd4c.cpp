#include <bits/stdc++.h>
using namespace std;



ifstream in ("cmmdc.in");

ofstream out ("cmmdc.out");



int main () {

    int a, b;

    in >> a >> b;

    int ans = __gcd(a, b);

    out << (ans == 1 ? 0 : ans);



    in.close();

    out.close();

    return 0;

}
