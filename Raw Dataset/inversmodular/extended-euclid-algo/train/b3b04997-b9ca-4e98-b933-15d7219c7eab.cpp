#include <bits/stdc++.h>


using namespace std;



long long aux;



void euclid(long long &x, long long &y, long long a, long long b)

{

    if(b == 0) {

        x = 1;

        y = 0;

    }

    else {

        euclid(x, y, b, a % b);

        aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}

int main()

{

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    long long a,n,inv = 0,ins;

    fin >> a >> n;

    euclid(inv, ins, a, n);

    if(inv <= 0)

        inv = n + inv % n;

    fout << inv << '\n';

}
