#include <bits/stdc++.h>




using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



long long n, v[100005], aib[100005];

pair <long long, long long> vRead[100005];



long long sum(int x)

{

    int s = 0;

    while (x) {

        s += aib[x];

        x -= x & (-x);

    }

    return s;

}



void add(int x, int val)

{

    while (x <= n) {

        aib[x] = (aib[x] + val) % 9917;

        x += x & (-x);

    }

}



void normalise()

{

    long long x;

    for (int i = 1; i <= n; ++i) {

        f >> x;

        vRead[i] = {x, i};

    }

    sort (vRead + 1, vRead + n + 1);

    for (int i = 1; i <= n; ++i) {

        v[i] = vRead[i].second;

    }

}



int main()

{

    f >> n;



    normalise();





    long long noOfInversions = 0;

    for (int i = n; i >= 1; --i) {

        noOfInversions = (noOfInversions + sum(v[i])) % 9917;

        add(v[i], 1);

    }

    g << noOfInversions;

    return 0;

}
